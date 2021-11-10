// g++ multiset.cpp -o multiset -std=c++11 -Wall
#include <set>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make multiset
    // multiset<value variable type>* [Variable_name] = new multiset<value variable type>
    multiset<string>* multiset_test = new multiset<string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">, <\"second\">, <\"third\"> \033[0m" << endl;
    multiset_test->insert("first");
    multiset_test->insert("second");
    multiset_test->insert("third");

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    multiset<string>::iterator iter;
    for( iter = multiset_test->begin(); iter != multiset_test->end(); iter++)
        cout << *iter << endl;

    // search
    cout << "\033[1;32m[+] search second\033[0m" << endl;
    iter = multiset_test->find("second");
    cout << *iter << endl;

    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    multiset_test->erase("second");
    for( iter = multiset_test->begin(); iter != multiset_test->end(); iter++)
        cout << *iter << endl;

    // insert
    cout << "\033[1;31m[+] insert <\"one\">, <\"two\">, <\"three\">\033[0m" << endl;
    multiset_test->insert("third");
    multiset_test->insert("first");
    multiset_test->insert("second");

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for( iter = multiset_test->begin(); iter != multiset_test->end(); iter++)
        cout << *iter << endl;

    // lower_bound & upper_bound
    // print specific value with key
    cout << "\033[1;32m[+] print value first\033[0m" << endl;
    for( iter = multiset_test->lower_bound("first"); iter != multiset_test->upper_bound("first"); iter++)
        cout << *iter << endl;
    cout << "\033[1;32m[+] print value second\033[0m" << endl;
    for( iter = multiset_test->lower_bound("second"); iter != multiset_test->upper_bound("second"); iter++)
        cout << *iter << endl;
    cout << "\033[1;32m[+] print value third\033[0m" << endl;
    for( iter = multiset_test->lower_bound("third"); iter != multiset_test->upper_bound("third"); iter++)
        cout << *iter << endl;

    // equal_range
    cout << "\033[1;32m[+] equal_range test / print value third\033[0m" << endl;
    pair< multiset<string>::iterator, multiset<string>::iterator >pair_test = multiset_test->equal_range("third");
    for( iter = pair_test.first; iter != pair_test.second; iter++)
        cout << *iter << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    multiset_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(multiset_test->empty())
        cout << "Empty!" << endl;
    
    return 0;
}
