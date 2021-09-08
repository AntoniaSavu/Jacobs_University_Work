/*
CH-230-A
a13_p4.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
using namespace std;

class A
{
  int x;

public:
  void setX(int i) { x = i; }
  void print() { cout << x; }
};

class B : public virtual A
{
public:
  B() { setX(10); }
};

class C : public virtual A
{
public:
  C() { setX(20); }
};

class D : public B, public C
{

  /*
  Because there are two instances of print()
  of A( one from inheriting B and one from inheriting C) there is ambiguity 
  and the compiler does not know what to do. The solution is to make virtual 
  inheritance (class B : public virtual A, class C : public virtual A).
  This will make it so that print() from A only appears once
  despite the diamond inheritance.

  Another solution would be to have method hiding and name hiding by implementhing the following:

  int x;

  public:
   void print() { cout << x; };

Inside of the class D.This way the compiler automatically hides the method of
the base class(mehtod hiding) and 
it will also hide member name x from class A(name hiding).
 But this will print 0, which I assume is not the intended outcome
*/
};

int main()
{
  D d;
  d.print();
  return 0;
}