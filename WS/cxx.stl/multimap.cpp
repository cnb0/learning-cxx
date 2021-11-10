// g++ multimap.cpp -o multimap -std=c++11 -Wall
#include <map>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make multimap
    // multimap<key variable type, value variable type>* [Variable_name] = new multimap< key variable type, value variable type>
    multimap<int, string>* multimap_test = new multimap<int, string>;

    // insert
    cout << "\033[1;31m[+] insert <1, \"first\">, <2, \"second\">, <3, \"third\"> \033[0m" << endl;
    multimap_test->insert( multimap<int, string>::value_type(1, "first"));
    multimap_test->insert( multimap<int, string>::value_type(2, "second"));
    multimap_test->insert( multimap<int, string>::value_type(3, "third"));

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    multimap<int, string>::iterator iter;
    for( iter = multimap_test->begin(); iter != multimap_test->end(); iter++)
        cout << iter->second << endl;

    // search
    cout << "\033[1;32m[+] search second\033[0m" << endl;
    iter = multimap_test->find(2);
    cout << iter->second << endl;

    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    multimap_test->erase(2);
    for( iter = multimap_test->begin(); iter != multimap_test->end(); iter++)
        cout << iter->second << endl;

    // insert
    cout << "\033[1;31m[+] insert <1, \"one\">, <2, \"two\">, <3, \"three\">\033[0m" << endl;
    multimap_test->insert( pair<int, string>(1, "one"));
    multimap_test->insert( pair<int, string>(2, "two"));
    multimap_test->insert( pair<int, string>(3, "three"));

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for( iter = multimap_test->begin(); iter != multimap_test->end(); iter++)
        cout << iter->second << endl;

    // lower_bound & upper_bound
    // print specific value with key
    cout << "\033[1;32m[+] print key 1\033[0m" << endl;
    for( iter = multimap_test->lower_bound(1); iter != multimap_test->upper_bound(1); iter++)
        cout << iter->second << endl;
    cout << "\033[1;32m[+] print key 2\033[0m" << endl;
    for( iter = multimap_test->lower_bound(2); iter != multimap_test->upper_bound(2); iter++)
        cout << iter->second << endl;
    cout << "\033[1;32m[+] print key 3\033[0m" << endl;
    for( iter = multimap_test->lower_bound(3); iter != multimap_test->upper_bound(3); iter++)
        cout << iter->second << endl;

    // equal_range
    cout << "\033[1;32m[+] equal_range test / print key 3\033[0m" << endl;
    pair< multimap<int, string>::iterator, multimap<int, string>::iterator >pair_test = multimap_test->equal_range(3);
    for( iter = pair_test.first; iter != pair_test.second; iter++)
        cout << iter->second << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    multimap_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(multimap_test->empty())
        cout << "Empty!" << endl;
    
    return 0;
}
