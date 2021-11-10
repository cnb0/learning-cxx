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
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cassert>

/*
    C++ examples for:
        std::find, std::find_if, std::find_if_not.
        std::all_of, std::any_of, std::none_of.
*/

// Common function to output results for finding in a vector.
template<typename VecType, typename IterType>
void Message(bool expecting_match,
             VecType& v,
             IterType it,
             std::string const& func_str,
             std::string const& lambda_str,
             std::string const& vec_name)
{
    if (expecting_match)
    {
        if (it != v.end())
        {
            std::cout << func_str;
            std::cout << ": found value " << *it;
            std::cout << " within " << vec_name;
            if (!lambda_str.empty())
                std::cout << " for lambda " << lambda_str;
            std::cout << std::endl;
        }
        else
            assert(false);
    }
    else
    {
        if (it != v.end())
            assert(false);
        else
        {
            std::cout << func_str << ": did not find value within " << vec_name;
            if (!lambda_str.empty())
                std::cout << " for lambda " << lambda_str;
            std::cout << std::endl;
        }
    }
}

void TestFind()
{
    std::vector<int> nums{ 0, 1, 2, 3, 4, 10, 11, 12, 13, 14 };
    std::vector<int> odd_nums{ 1, 3, 11, 13 };
    std::vector<int> even_nums{ 0, 2, 4, 10, 12, 14 };

    char const* find_str = "find";

    // test odd and even for nums.
    Message(true, nums, std::find(nums.begin(), nums.end(), 13), find_str, "", "nums");
    Message(true, nums, std::find(nums.begin(), nums.end(), 14), find_str, "", "nums");
    Message(true, odd_nums, std::find(odd_nums.begin(), odd_nums.end(), 1), find_str, "", "odd_nums");
    Message(false, odd_nums, std::find(odd_nums.begin(), odd_nums.end(), 0), find_str, "", "odd_nums");
    Message(false, even_nums, std::find(even_nums.begin(), even_nums.end(), 1), find_str, "", "even_nums");
    Message(true, even_nums, std::find(even_nums.begin(), even_nums.end(), 0), find_str, "", "even_nums");
}

void TestFindIf()
{
    std::vector<int> nums{ 0, 1, 2, 3, 4, 10, 11, 12, 13, 14 };
    std::vector<int> odd_nums{ 1, 3, 11, 13 };
    std::vector<int> even_nums{ 0, 2, 4, 10, 12, 14 };

    auto IsOdd = [](int i) { return i % 2 != 0; };
    auto IsEven = [](int i) { return i % 2 == 0; };
    char const* find_str = "find_if";

    // test odd and even for nums.
    Message(true, nums, std::find_if(nums.begin(), nums.end(), IsOdd), find_str, "IsOdd", "nums");
    Message(true, nums, std::find_if(nums.begin(), nums.end(), IsEven), find_str, "IsEven", "nums");
    Message(true, odd_nums, std::find_if(odd_nums.begin(), odd_nums.end(), IsOdd), find_str, "IsOdd", "odd_nums");
    Message(false, odd_nums, std::find_if(odd_nums.begin(), odd_nums.end(), IsEven), find_str, "IsEven", "odd_nums");
    Message(false, even_nums, std::find_if(even_nums.begin(), even_nums.end(), IsOdd), find_str, "IsOdd", "even_nums");
    Message(true, even_nums, std::find_if(even_nums.begin(), even_nums.end(), IsEven), find_str, "IsEven", "even_nums");
}

void TestFindIfNot()
{
    std::vector<int> nums{ 0, 1, 2, 3, 4, 10, 11, 12, 13, 14 };
    std::vector<int> odd_nums{ 1, 3, 11, 13 };
    std::vector<int> even_nums{ 0, 2, 4, 10, 12, 14 };

    auto IsOdd = [](int i) { return i % 2 != 0; };
    auto IsEven = [](int i) { return i % 2 == 0; };
    char const* find_str = "find_if_not";

    // test odd and even for nums.
    Message(true, nums, std::find_if_not(nums.begin(), nums.end(), IsOdd), find_str, "IsOdd", "nums");
    Message(true, nums, std::find_if_not(nums.begin(), nums.end(), IsEven), find_str, "IsEven", "nums");
    Message(false, odd_nums, std::find_if_not(odd_nums.begin(), odd_nums.end(), IsOdd), find_str, "IsOdd", "odd_nums");
    Message(true, odd_nums, std::find_if_not(odd_nums.begin(), odd_nums.end(), IsEven), find_str, "IsEven", "odd_nums");
    Message(true, even_nums, std::find_if_not(even_nums.begin(), even_nums.end(), IsOdd), find_str, "IsOdd", "even_nums");
    Message(false, even_nums, std::find_if_not(even_nums.begin(), even_nums.end(), IsEven), find_str, "IsEven", "even_nums");
}

void TestAllOf()
{
    std::vector<int> nums{ 0, 1, 2, 3, 4, 10, 11, 12, 13, 14 };
    auto IsOdd = [](int i) { return i % 2 != 0; };
    auto IsSmall = [](int i) { return i < 20; };
    auto IsMedium = [](int i) { return i < 10; };
    auto IsLarge = [](int i) { return i > 20; };

    // test odd and even for nums.
    std::cout << "std::all_of: "
              << (std::all_of(nums.begin(), nums.end(), IsOdd) ? "found" : "did not find")
              << " odd value" << std::endl;

    std::cout << "std::all_of: "
              << (std::all_of(nums.begin(), nums.end(), IsSmall) ? "found" : "did not find")
              << " small value" << std::endl;

    std::cout << "std::all_of: "
              << (std::all_of(nums.begin(), nums.end(), IsMedium) ? "found" : "did not find")
              << " medium value" << std::endl;

    std::cout << "std::all_of: "
              << (std::all_of(nums.begin(), nums.end(), IsLarge) ? "found" : "did not find")
              << " large value" << std::endl;
}

void TestAnyOf()
{
    std::vector<int> nums{ 0, 1, 2, 3, 4, 10, 11, 12, 13, 14 };
    auto IsOdd = [](int i) { return i % 2 != 0; };
    auto IsSmall = [](int i) { return i < 20; };
    auto IsMedium = [](int i) { return i < 10; };
    auto IsLarge = [](int i) { return i > 20; };

    // test odd and even for nums.
    std::cout << "std::any_of: "
              << (std::any_of(nums.begin(), nums.end(), IsOdd) ? "found" : "did not find")
              << " odd value" << std::endl;

    std::cout << "std::any_of: "
              << (std::any_of(nums.begin(), nums.end(), IsSmall) ? "found" : "did not find")
              << " small value" << std::endl;

    std::cout << "std::any_of: "
              << (std::any_of(nums.begin(), nums.end(), IsMedium) ? "found" : "did not find")
              << " medium value" << std::endl;

    std::cout << "std::any_of: "
              << (std::any_of(nums.begin(), nums.end(), IsLarge) ? "found" : "did not find")
              << " large value" << std::endl;
}

int main()
{
    TestFind();
    TestFindIf();
    TestFindIfNot();
    TestAllOf();
    TestAnyOf();

    return 0;
}
