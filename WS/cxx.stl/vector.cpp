// g++ vector.cpp -o vector -std=c++11 -Wall
#include <vector>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make vector
    // vector<value variable type>* [Variable_name] = new vector<value variable type>
    vector<string>* vt_test = new vector<string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">, <\"second\">, <\"third\"> \033[0m" << endl;
    vt_test->push_back("first");
    vt_test->push_back("second");
    vt_test->push_back("third");
    // vt_test->assign(10, "test");

    // print specific things
    cout << "\033[1;32m[+] print specific things\033[0m" << endl;
    cout << vt_test->at(0) << endl;
    cout << vt_test->back() << endl;;

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    vector<string>::iterator iter;
    for(iter = vt_test->begin(); iter != vt_test->end(); iter++)
        cout << *iter << endl;
    
    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    vt_test->erase(vt_test->begin()+1);
    for( iter = vt_test->begin(); iter != vt_test->end(); iter++)
        cout << *iter << endl;

    // insert
    cout << "\033[1;31m[+] insert <\"second\">\033[0m" << endl;
    vt_test->insert(vt_test->begin() + 1, "second");

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = vt_test->begin(); iter != vt_test->end(); iter++)
        cout << *iter << endl;

    // print front value
    cout << "\033[1;32m[+] print front value\033[0m" << endl;
    cout << vt_test->front() << endl;
    
    // pop_back
    cout << "\033[1;32m[+] pop back value\033[0m" << endl;
    vt_test->pop_back();

    // print all
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    for(iter = vt_test->begin(); iter != vt_test->end(); iter++)
        cout << *iter << endl;
    
    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    vt_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(vt_test->empty())
        cout << "Empty!" << endl;

    // swap
    // vector<string> vt_test1, vt_test2;
    // vt_test.push_back("first");
    // vt_test.push_back("second");
    // vt_test.swap(vt_test2);
    return 0;
}

// STL Vector
// at()
// back()
// begin()
// clear()
// empty()
// end()
// erase()
// front()
// insert()
// max_size()
// pop_back()
// push_back()
// rbegin()
// resize
// reserve
// size
// swap

