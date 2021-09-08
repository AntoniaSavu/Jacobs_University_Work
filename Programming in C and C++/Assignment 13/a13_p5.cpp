/*
CH-230-A
a13_p5.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A(int i) { x = i; }
    void print() { cout << x; }
};

class B : virtual public A
{
public:
    B() : A(10) {}
};

class C : virtual public A
{
public:
    C() : A(10) {}
};

class D : public B, public C
{
public:
    D() : A(10) {}
};

/*
The problem is that we are trying to initialise
an object (d) of type D with the default(empty)
constructor, when the class does not have one.
This is followed up by alot of other nasty errors,
but they all stem from this one error. The fix I
thought of is to just provide a definiton for the 
default constructor, for instance the one I implemented
at line 34. This fixes the first error, that we are trying to call
a deleted function(the empty constructor) and consequently all the other 
error as they are related.
*/

int main()
{
    D d;
    d.print();
    return 0;
}