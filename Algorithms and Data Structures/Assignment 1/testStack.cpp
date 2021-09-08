/*
CH-231-A
testStack.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    //instance of Stack that store ints
    Stack<int> a;
    a.push(20);
    for (int i = 0; i < 8; i++)
        a.push(i + 1);
    a.push(10);
    a.print();
    a.push(11);
    //when we try to push 11, it does not work because the stack is full

    int entries;
    entries = a.getNumEntries();
    std::cout << entries;
    //testing the entries method

    std::cout << '\n'
              << "--------------------------------"
              << '\n';
    //instance of Stack using chars(with size parameter)
    Stack<char> b(15);
    b.push('a');
    for (int i = 0; i < 14; i++)
        b.push(i + 67);
    b.print();
    char popped;
    for (int i = 0; i < 15; i++)
        b.pop(popped);
    b.pop(popped);
    //when we try to pop for the 16th time it
    //does not work because the stack is empty
    b.push('-');
    char top_of_stack;
    top_of_stack = b.back(); //testing the back method
    std::cout << top_of_stack;
    return 0;
}