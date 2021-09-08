/* 
The most instructive thing is to compile, run and observe the output
of this program. Later, do the same thing with randomvirtual and
observe the differences.
*/

#include <iostream>
#include <cstdlib> // for random and srandom
#include <stdlib.h>

using namespace std;

const int dimension = 10;

double random01(); // returns a random number between 0 and 1

// Dummy base class. Just print a message to indentify itself
class BaseClass
{
private:
    int something; // needs some data (to avoid some subtle problems). We will not use it
public:
    BaseClass()
    {
        something = 0;
        cout << "BaseClass constructor called" << endl;
    }
    void print() const { cout << "BaseClass print" << endl; };
};

class DerivedOne : public BaseClass
{ // derives from BaseClass
public:
    DerivedOne() { cout << "DerivedOne constructor called" << endl; }
    void print() const { cout << "DerivedOne print" << endl; } // redefinition of method print
};

class DerivedTwo : public BaseClass
{ // derives from BaseClass
public:
    DerivedTwo() { cout << "DerivedTwo constructor called" << endl; }
    void print() const { cout << "DerivedTwo print" << endl; } // redefinition of method print
};

int main(int argc, char **argv)
{

    BaseClass b1;
    BaseClass d1 = DerivedOne();
    BaseClass d2 = DerivedTwo();

    cout << "Sizeof BaseClass: " << sizeof(BaseClass) << endl;

    b1.print(); // will print "BaseClass print"
    d1.print(); // also here
    d2.print(); // and also here

    unsigned int seed;
    cout << "Provide a random seed:";
    cin >> seed;
    srand(seed);

    BaseClass *list[dimension];
    int i;

    // This cycle randomly assigns elemnts in list as DerivedOne or DerivedTwo
    for (i = 0; i < dimension; i++)
    {
        if (random01() < 0.5)
            list[i] = new DerivedOne; // Ok: BaseClass is needed, but Derived one can be assigned
        else
            list[i] = new DerivedTwo(); // also here
    }

    for (i = 0; i < dimension; i++)
    {
        list[i]->print(); // will always print "BaseClass print"
        delete list[i];
    }
}

// Returns a random number between 0 and 1. Makes a (very poor) use of the random standard C function
double random01()
{
    return (double)rand() / RAND_MAX; // random returns an int between 0 and RAND_MAX. This way we clip it into 0,1
}
