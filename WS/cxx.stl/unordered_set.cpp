// g++ unorderedset.cpp -o unorderedset -std=c++11 -Wall
#include <unordered_set>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make unordered_set
    // unordered_set<value variable type>* [Variable_name] = new unordered_set<value variable type>
    unordered_set<string>* uos_test = new unordered_set<string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">, <\"second\">, <\"third\"> \033[0m" << endl;
    uos_test->insert("first");
    uos_test->insert("second");
    uos_test->insert("third");

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    unordered_set<string>::iterator iter;
    for( iter = uos_test->begin(); iter != uos_test->end(); iter++)
        cout << *iter << endl;

    // search
    cout << "\033[1;32m[+] search second\033[0m" << endl;
    iter = uos_test->find("second");
    cout << *iter << endl;

    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    uos_test->erase("second");
    for( iter = uos_test->begin(); iter != uos_test->end(); iter++)
        cout << *iter << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    uos_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(uos_test->empty())
        cout << "Empty!" << endl;

    return 0;
}
