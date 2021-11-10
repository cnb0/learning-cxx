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

void f1(int i)
{
    std::cout << "f1(" << i << ")" << std::endl;
}

void f2(int i1, int i2)
{
    std::cout << "f2(" << i1 << ", " << i2 << ")" << std::endl;
}

int main()
{
    // Bind the function and arguments to a function that takes no arguments.
    std::function<void()> func1a = std::bind(f1, 1);
    func1a();

    // Bind the function and arguments to a function that takes one argument,
    // and bind the argument to the function.
    // Note the placeholder defines which argument is bound to the function.
    std::function<void(int)> func1b = std::bind(f1, std::placeholders::_1);
    func1b(2);

    // Bind the function and arguments to a function that takes two arguments,
    // and bind the arguments to the function.
    std::function<void(int, int)> func2a = std::bind(f2, std::placeholders::_1, std::placeholders::_2);
    func2a(1, 2);

    // Bind the function and arguments to a function that takes two arguments,
    // and bind the arguments to the function, swapping the two arguments.
    std::function<void(int, int)> func2b = std::bind(f2, std::placeholders::_2, std::placeholders::_1);
    func2b(1, 2);

    return 0;
}
