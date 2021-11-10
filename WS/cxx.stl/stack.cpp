// g++ stack.cpp -o stack -std=c++11 -Wall
#include <stack>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    // how2make queue
    // queue<value variable type>* [Variable_name] = new queue<value variable type>
    stack<string>* stack_test = new stack<string>;

    // insert
    cout << "\033[1;31m[+] insert <\"first\">, <\"second\">, <\"third\"> \033[0m" << endl;
    stack_test->push("first");
    stack_test->push("second");
    stack_test->push("third");

    // print specific things
    cout << "\033[1;32m[+] print stack's top\033[0m" << endl;
    cout << stack_test->top() << endl;

    // pop
    cout << "\033[1;32m[+] pop\033[0m" << endl;
    cout << stack_test->top() << endl;
    stack_test->pop();
    cout << stack_test->top() << endl;
    stack_test->pop();
    cout << stack_test->top() << endl;
    stack_test->pop();   

    cout << "\033[1;32m[+] isempty?\033[0m" << endl;
    if(stack_test->empty())
        cout << "Empty! size : " << stack_test->size() << endl;

    return 0;
}
