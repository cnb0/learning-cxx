// g++ list.cpp -o list -std=c++11 -Wall
#include <list>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make list
    // list<value variable type>* [Variable_name] = new list<value variable type>
    list<string>* list_test = new list<string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">, <\"second\">, <\"third\"> \033[0m" << endl;
    list_test->push_back("second");
    list_test->push_front("first");
    list_test->push_back("third");
    // list_test->assign(10, "test");

    // // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    list<string>::iterator iter;
    for(iter = list_test->begin(); iter != list_test->end(); iter++)
        cout << *iter << endl;
    
    // erase
    cout << "\033[1;32m[+] erase first\033[0m" << endl;
    list_test->erase(list_test->begin());
    for( iter = list_test->begin(); iter != list_test->end(); iter++)
        cout << *iter << endl;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">\033[0m" << endl;
    list_test->insert(list_test->begin(), "first");

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = list_test->begin(); iter != list_test->end(); iter++)
        cout << *iter << endl;

    // print front value
    cout << "\033[1;32m[+] print front value\033[0m" << endl;
    cout << list_test->front() << endl;
    
    // pop_back
    cout << "\033[1;32m[+] pop back value\033[0m" << endl;
    list_test->pop_back();

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = list_test->begin(); iter != list_test->end(); iter++)
        cout << *iter << endl;

    // pop_front
    cout << "\033[1;32m[+] pop front value\033[0m" << endl;
    list_test->pop_front();

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = list_test->begin(); iter != list_test->end(); iter++)
        cout << *iter << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    list_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(list_test->empty())
        cout << "Empty!" << endl;

    delete list_test;

    list<int>* list_test2 = new list<int>;
    list_test2->push_back(23);
    list_test2->push_back(1);
    list_test2->push_back(42);

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    list<int>::iterator iter2;
    for(iter2 = list_test2->begin(); iter2 != list_test2->end(); iter2++)
        cout << *iter2 << endl;

    // sort ascending order
    list_test2->sort();
    cout << "\033[1;32m[+] sort!\033[0m" << endl;
    for(iter2 = list_test2->begin(); iter2 != list_test2->end(); iter2++)
        cout << *iter2 << endl;

    // sort descending order
    list_test2->sort(greater<int>());
    cout << "\033[1;32m[+] sort!\033[0m" << endl;
    for(iter2 = list_test2->begin(); iter2 != list_test2->end(); iter2++)
        cout << *iter2 << endl;

    return 0;
}
