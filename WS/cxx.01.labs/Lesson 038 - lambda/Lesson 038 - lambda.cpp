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
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int i1 = 0;
    int i2 = 1;

    /*
        Beginning with C++ 11 it is possible to define lambda expressions
        that can be used where it is defined.
        These are anonymous functions, which are also known as closures.
    */

    // Lambda can be defined and a assigned to a name, such as p.
    // This is an example of a pow function implemented as a lambda.
    auto GetPow = [](auto base, auto exponent)
    {
        auto t = base;
        while (exponent-- > 1)
            t *= base;
        return t;
    };

    // Will output 27.
    std::cout << GetPow(3, 3) << std::endl;

    // The lambda can also be defined and executed in place.
    // This is done by calling it like any function after it's defined.
    // Notice (2, 4) passed to the function after definition, and will output 16.
    // Note that i1 an i2 are not visible in the scope of the following lambda.
    std::cout << [](auto base, auto exponent)
    {
        auto t = base;
        while (exponent-- > 1)
            t *= base;
        return t;
    }(2, 4) << std::endl;

    // lambda can be given visibility of variables outside the scope of the lambda.
    // These external variables are treated as pass by value (non-modifiable).
    // Output will be 0 1.
    [=] { std::cout << i1 << " " << i2 << std::endl; }();

    // lambda can also be given visibility of variables outside the scope of the
    // lambda by reference, allowing them to be modified.
    // Output will be 1 2.
    [&] {i1++; i2++;  std::cout << i1 << " " << i2 << std::endl; }();

    // We can see that the previous lambda has modified i1 as 1 and i2 as 2.
    // Output will be 1 2.
    [=] { std::cout << i1 << " " << i2 << std::endl; }();

    // It is also possible to specify access to externals by reference or value for any
    // variables defined outside the scope of the lambda.
    // Note that i1 cannot be modified within the lambda.
    // Output will be 1 3.
    [i1, &i2] { i2++;  std::cout << i1 << " " << i2 << std::endl; }();

    // We can see that the previous lambda has modified i2 as 3.
    // Output will be 1 3.
    [=] { std::cout << i1 << " " << i2 << std::endl; }();

    // It's also possible to use a lambda as a function callback within std::for_each.
    // Output will 1 4 7.
    std::vector<int> v{ 1,4,7 };
    std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    // Notice that even though the lambda is called by for_each, i1 will be incremented
    // for each element in v.
    std::for_each(v.begin(), v.end(), [&i1](int i) { ++i1;  std::cout << i << " "; });
    std::cout << std::endl;

    // Output will be 4.
    std::cout << i1 << std::endl;

    return 0;
}
