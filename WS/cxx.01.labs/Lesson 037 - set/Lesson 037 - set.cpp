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
#include <set>

int main()
{
    /*
        The standard library provides the set class that can store, find and erase unique values.

        This lookup will generally perform considerably faster than sequentially searching
        a vector or list, unless the set has only a few items.

        The set will be sorted by the value, so a compare function would need to be provided,
        if you are using a custom type for the value.

        Primitive types such as int or long, library types like std::string can be used
        as a value without providing your own compare function.

        Writing your own compare function is not covered in this lesson.
    */

    std::set<std::string> string_lookup;

    string_lookup.insert("One");
    string_lookup.insert("Two");
    string_lookup.insert("Three");
    string_lookup.insert("Four");
    string_lookup.insert("Five");

    std::string value_to_find = "One";
    std::set<std::string>::iterator pos = string_lookup.find(value_to_find);

    // The lookup will find the string "One" for the integer value 1.
    if (pos != string_lookup.end())
        std::cout << "Value found " << *pos << std::endl;
    else
        std::cout << "Value not found " << value_to_find << "!" << std::endl;

    // The lookup will not find a string for the integer value 6. 
    value_to_find = "Six";
    pos = string_lookup.find(value_to_find);
    if (pos != string_lookup.end())
        std::cout << "Value found " << *pos << std::endl;
    else
        std::cout << "Value not found " << value_to_find << "!" << std::endl;

    // It is still possible to loop through all the values in a set, and we can display all values.
    for (pos = string_lookup.begin(); pos != string_lookup.end(); ++pos)
        std::cout << "Value found " << *pos << std::endl;

    return 0;
}
