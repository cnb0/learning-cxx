/*
Copyright 2018 Colin Girling

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <mutex>
#include <queue>
#include <thread>
#include <chrono>
#include <memory>
#include <cstdint>
#include <iostream>

namespace
{
    std::mutex g_cout_mutex;
}

template<typename T>
void Print(T arg)
{
    std::lock_guard<std::mutex> lock(g_cout_mutex);
    std::cout << arg << std::endl;
}

template<typename T1, typename T2>
void Print(T1 arg1, T2 arg2)
{
    std::lock_guard<std::mutex> lock(g_cout_mutex);
    std::cout << arg1 << arg2 << std::endl;
}

// Provide thread safe queue which will push values upto max_value,
// and can pop added values.
class ThreadedQueue
{
public:
    static std::uint32_t const max_value = 5;

    // Push value onto queue in a thread-safe way.
    bool Push(std::uint32_t& pushed_value)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        bool pushed = m_next_value <= max_value;
        if (pushed)
        {
            m_values.push(m_next_value);
            pushed_value = m_next_value;
            ++m_next_value;
        }
        return pushed;
    }

    // Pop value onto queue in a thread-safe way.
    bool Pop(std::uint32_t& popped_value)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        bool popped = !m_values.empty();
        if (popped)
        {
            popped_value = m_values.front();
            m_values.pop();
        }
        return popped;
    }

    // Check if the next value is past max value.
    bool MoreToPush() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_next_value <= max_value;
    }

    bool MoreToPop() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_next_value <= max_value || !m_values.empty();
    }

private:
    mutable std::mutex m_mutex;
    std::queue<std::uint32_t> m_values;
    std::uint32_t m_next_value = 1;
};

// Keep adding values to to the queue until the maximum value is reached.
void ThreadLoopPush(ThreadedQueue& threaded_queue)
{
    Print("Push started");

    while (threaded_queue.MoreToPush())
    {
        std::uint32_t pushed_value;
        if (threaded_queue.Push(pushed_value))
            Print("Pushed ", pushed_value);

        // Force the thread to yield some time for the other thread to pop values.
        // NOTE: std::this_thread::yield() does not guarantee yielding enough time
        //       to other threads on all platforms for displaying interleaved output.
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    Print("Push finished");
}

// Keep removing values to to the queue until the maximum value is reached
// and there is nothing left in the queue.
void ThreadLoopPop(ThreadedQueue& threaded_queue)
{
    Print("Pop started");

    while (threaded_queue.MoreToPop())
    {
        std::uint32_t popped_value;
        if (threaded_queue.Pop(popped_value))
            Print("Popped ", popped_value);
    }

    Print("Pop finished");
}

int main()
{
    ThreadedQueue threaded_queue;
    std::thread t1(ThreadLoopPush, std::ref(threaded_queue));
    std::thread t2(ThreadLoopPop, std::ref(threaded_queue));
    t2.join();
    t1.join();

    return 0;
}
