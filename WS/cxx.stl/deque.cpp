// g++ deque.cpp -o deque -std=c++11 -Wall
#include <deque>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make deque
    // deque<value variable type>* [Variable_name] = new deque<value variable type>
    deque<string>* dq_test = new deque<string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">, <\"second\">, <\"third\"> \033[0m" << endl;
    dq_test->push_back("second");
    dq_test->push_front("first");
    dq_test->push_back("third");
    // dq_test->assign(10, "test");

    // print specific things
    cout << "\033[1;32m[+] print specific things\033[0m" << endl;
    cout << dq_test->at(0) << endl;
    cout << dq_test->back() << endl;;

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    deque<string>::iterator iter;
    for(iter = dq_test->begin(); iter != dq_test->end(); iter++)
        cout << *iter << endl;
    
    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    dq_test->erase(dq_test->begin()+1);
    for( iter = dq_test->begin(); iter != dq_test->end(); iter++)
        cout << *iter << endl;

    // insert
    cout << "\033[1;31m[+] insert <\"second\">\033[0m" << endl;
    dq_test->insert(dq_test->begin() + 1, "second");

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = dq_test->begin(); iter != dq_test->end(); iter++)
        cout << *iter << endl;

    // print front value
    cout << "\033[1;32m[+] print front value\033[0m" << endl;
    cout << dq_test->front() << endl;
    
    // pop_back
    cout << "\033[1;32m[+] pop back value\033[0m" << endl;
    dq_test->pop_back();

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = dq_test->begin(); iter != dq_test->end(); iter++)
        cout << *iter << endl;

    // pop_front
    cout << "\033[1;32m[+] pop front value\033[0m" << endl;
    dq_test->pop_front();

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = dq_test->begin(); iter != dq_test->end(); iter++)
        cout << *iter << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    dq_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(dq_test->empty())
        cout << "Empty!" << endl;

    // swap
    // deque<string> dq_test1, dq_test2;
    // dq_test.push_back("first");
    // dq_test.push_back("second");
    // dq_test.swap(dq_test2);
    return 0;
}
