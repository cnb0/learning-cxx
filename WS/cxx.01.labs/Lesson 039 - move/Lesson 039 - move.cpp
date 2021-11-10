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

#include <cstring>
#include <algorithm>
#include <cstddef>
#include <cassert>


/*
Since C++ 11 it has been possible to use the && operator to
move ownership of values between objects.

This can be done by implementing a move constructor and move assignment operator.

The standard library also provides std::move to assist in moving objects.

These examples are designed to be an introduction into moving objects, and does not
cover other topics such as perfect forwarding, which are related to move semantics.
*/
class SampleString
{
public:
    // Typical example of copying a C string pointer via constructor.
    SampleString(char const* s = nullptr)
        : m_length(s != nullptr ? ::strlen(s) : 0)
    {
        InternalCopy(s, m_length);
    }

    // Typical example of copying a string object via constructor.
    SampleString(SampleString const& s)
        : m_length(s.length())
    {
        InternalCopy(s.c_str(), m_length);
    }

    // Move constructor, which will take ownership of the string pointer from s.
    // Note this example is not thread-safe.
    SampleString(SampleString&& s)
    {
        if (this != &s)
        {
            m_length = s.m_length;
            m_string = s.m_string;
            s.m_length = 0;
            s.m_string = nullptr;
        }
    }

    ~SampleString()
    {
        delete[] m_string;
    }

    // Typical example of copying a string object.
    SampleString& operator =(SampleString const& s)
    {
        m_length = s.length();
        delete[] m_string;
        InternalCopy(s.c_str(), m_length);
    }

    // Move assignment operator, which will take ownership of the string pointer from s.
    // Note this example is not thread-safe.
    SampleString& operator =(SampleString&& s)
    {
        if (this != &s)
        {
            m_length = s.m_length;;
            m_string = s.m_string;
            s.m_length = 0;
            s.m_string = nullptr;
        }
        return *this;
    }

    bool empty() const noexcept
    {
        return m_length == 0 && m_string == nullptr;
    }

    std::size_t length() const noexcept
    {
        return m_length;
    }

    char const* c_str() const noexcept
    {
        return m_string ? m_string : "";
    }

private:
    // Only copy the string, as m_length is set outside this function.
    // Any existing m_string pointer needs to be freed before using this function.
    void InternalCopy(char const* s, std::size_t length)
    {
        if (length > 0)
        {
            m_string = new char[length + 1];
            ::memcpy(m_string, s, length + 1);
        }
        else
            m_string = nullptr;
    }

private:
    std::size_t m_length;
    char* m_string;
};

int main()
{
    constexpr char const* init_str = "Hello";

    SampleString s(init_str);

    // The pointer internally to s will change ownership to s2, and s will be clear.
    SampleString s2(std::move(s));
    assert(s.empty());
    assert(::strcmp(s2.c_str(), init_str) == 0);
    assert(s2.length() == 5);

    // Move using move assignment operator also transfers string ownership.
    SampleString s3;
    s3 = std::move(s2);
    assert(s2.empty());
    assert(::strcmp(s3.c_str(), init_str) == 0);
    assert(s3.length() == 5);

    // Temporary string objects will be automatically moved, without the need to use std::move.
    SampleString s4(SampleString("Goodbye"));
    assert(::strcmp(s4.c_str(), "Goodbye") == 0);
    assert(s4.length() == 7);

    return 0;
}
