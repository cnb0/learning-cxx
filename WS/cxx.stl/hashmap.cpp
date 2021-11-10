// g++ hashmap.cpp -o hashmap -std=c++11 -Wall
#include <hash_map>
#include <iostream>
#include <stdint.h>

using namespace std;
using namespace __gnu_cxx;

int main(int argc, char *argv[])
{
	// how2make hash_map
	// hash_map< key variable type, value variable type>* [Variable_name] = new hash_map< key variable type, value variable type>
	hash_map<int, string>* hm_test = new hash_map<int, string>;

	// insert
	cout << "\033[1;31m[+] insert <1, \"first\">, <2, \"second\">, <3, \"third\"> \033[0m" << endl;
	hm_test->insert( hash_map<int, string>::value_type(1, "first"));
	hm_test->insert( hash_map<int, string>::value_type(2, "second"));
	hm_test->insert( hash_map<int, string>::value_type(3, "third"));

	// print
	cout << "\033[1;32m[+] print begin to end\033[0m" << endl;
	hash_map<int, string>::iterator iter;
	for(iter = hm_test->begin(); iter != hm_test->end(); iter++)
		cout << iter->second << endl;

	// search
	cout << "\033[1;32m[+] search key number 2\033[0m" << endl;
	iter = hm_test->find(2);
	cout << iter->second << endl;

	// erase
	cout << "\033[1;32m[+] erase key number 1\033[0m" << endl;
	hm_test->erase(1);
	for(iter = hm_test->begin(); iter != hm_test->end(); iter++)
		cout << iter->second << endl;

	cout << "\033[1;32m[+] erase all keys\033[0m" << endl;
	// like hm_test.clear();
	hm_test->erase(hm_test->begin(), hm_test->end());
	for(iter = hm_test->begin(); iter != hm_test->end(); iter++)
		cout << iter->second << endl;

	// check!
	cout << "\033[1;32m[+] isempty?\033[0m" << endl;
	if(hm_test->empty())
		cout << "Empty!" << endl;

	return 0;
}

