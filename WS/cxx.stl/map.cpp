// g++ map.cpp -o map -std=c++11 -Wall
#include <map>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make map
    // map<key variable type, value variable type>* [Variable_name] = new map< key variable type, value variable type>
    map<int, string>* map_test = new map<int, string>;

    // insert
    cout << "\033[1;31m[+] insert <1, \"first\">, <2, \"second\">, <3, \"third\"> \033[0m" << endl;
    map_test->insert( map<int, string>::value_type(1, "first"));
    map_test->insert( map<int, string>::value_type(2, "second"));
    map_test->insert( map<int, string>::value_type(3, "third"));

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    map<int, string>::iterator iter;
    for( iter = map_test->begin(); iter != map_test->end(); iter++)
        cout << iter->second << endl;

    // search
    cout << "\033[1;32m[+] search second\033[0m" << endl;
    iter = map_test->find(2);
    cout << iter->second << endl;

    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    map_test->erase(2);
    for( iter = map_test->begin(); iter != map_test->end(); iter++)
        cout << iter->second << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    map_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(map_test->empty())
        cout << "Empty!" << endl;

    return 0;
}
