// g++ set.cpp -o set -std=c++11 -Wall
#include <set>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make set
    // set<value variable type>* [Variable_name] = new set<value variable type>
    set<string>* set_test = new set<string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">, <\"second\">, <\"third\"> \033[0m" << endl;
    set_test->insert("first");
    set_test->insert("second");
    set_test->insert("third");

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    set<string>::iterator iter;
    for( iter = set_test->begin(); iter != set_test->end(); iter++)
        cout << *iter << endl;

    // search
    cout << "\033[1;32m[+] search second\033[0m" << endl;
    iter = set_test->find("second");
    cout << *iter << endl;

    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    set_test->erase("second");
    for( iter = set_test->begin(); iter != set_test->end(); iter++)
        cout << *iter << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    set_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(set_test->empty())
        cout << "Empty!" << endl;

    return 0;
}
