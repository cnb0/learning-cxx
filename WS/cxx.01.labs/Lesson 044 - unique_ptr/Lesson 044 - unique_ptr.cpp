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

#include <memory>
#include <chrono>
#include <cstdint>
#include <string>
#include <iostream>

struct Person
{
    std::string m_first_name;
    std::string m_last_name;

    void Print(std::string const& msg)
    {
        std::cout << msg << m_first_name << " " << m_last_name << std::endl;
    }
};

int main()
{
    // Unique pointer takes ownership of the raw pointer.
    std::unique_ptr<Person> p1(new Person { "Bob", "Smith" });
    p1->Print("p1 = ");

    // Second unique pointer has ownership transferred from first unique pointer.
    std::unique_ptr<Person> p2(std::move(p1));
    if (p1)
        p1->Print("p1 = ");
    else
        std::cout << "p1 is null" << std::endl;
    p2->Print("p2 = ");

    // Raw pointer is released from unique pointer.
    Person* raw_p = p2.release();

    raw_p->Print("raw_p = ");

    p2.reset(raw_p);
    p2->Print("p2 = ");

    return 0;
}
