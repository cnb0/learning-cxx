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

#include <iostream>
#include <functional>

void f1()
{
    std::cout << "f1()" << std::endl;
}

void f2(int i)
{
    std::cout << "f2(" << i << ")" << std::endl;
}

struct functor
{
    void operator()() const
    {
        std::cout << "functor" << std::endl;
    }
};

int main()
{
    // Example of using a std::function object to store and use a function.
    std::function<void()> func1(f1);
    func1();

    // Example of using a std::function object to store and use a function with an argument.
    std::function<void(int)> func2(f2);
    func2(1);

    // Example of using a std::function object to store and use a lambda expression.
    std::function<void(char const*)> func3([](char const* s) { std::cout << "lambda(" << s << ")" << std::endl; });
    func3("Hello");

    // Example of using a std::function object to store and use a functor.
    functor func;
    std::function<void()> func4(func);
    func4();

    return 0;
}
