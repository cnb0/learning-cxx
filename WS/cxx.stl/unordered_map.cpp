// g++ unordered_map.cpp -o unordered_map -std=c++11 -Wall
#include <unordered_map>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make unordered_map
    // unordered_map<value variable type>* [Variable_name] = new unordered_set<value variable type>
    unordered_map<string, string>* uom_test = new unordered_map<string, string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\", \"1\">, <\"second\",\"2\">, <\"third\",\"3\"> \033[0m" << endl;
    uom_test->insert(unordered_map<string, string>::value_type("first","1"));
    uom_test->insert(unordered_map<string, string>::value_type("second","2"));
    uom_test->insert(unordered_map<string, string>::value_type("third","3"));

    // print
    cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
    unordered_map<string, string>::iterator iter;
    for( iter = uom_test->begin(); iter != uom_test->end(); iter++)
        cout << iter->first << " : " << iter->second << endl;

    // search
    cout << "\033[1;32m[+] search second\033[0m" << endl;
    iter = uom_test->find("second");
    cout << iter->first << " : " << iter->second << endl;

    // erase
    cout << "\033[1;32m[+] erase second\033[0m" << endl;
    uom_test->erase("second");
    for( iter = uom_test->begin(); iter != uom_test->end(); iter++)
        cout << iter->first << " : " << iter->second << endl;

    // clear
    cout << "\033[1;32m[+] clear all\033[0m" << endl;
    uom_test->clear();

    // isempty?
    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(uom_test->empty())
        cout << "Empty!" << endl;

    return 0;
}
