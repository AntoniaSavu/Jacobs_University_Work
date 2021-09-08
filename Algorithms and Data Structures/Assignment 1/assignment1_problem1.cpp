/*
CH-231-A
a1_p1.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <string>
using namespace std;
// the classic Complex class which can be found
// in the professor's source code
class Complex {
private:
  double re, im;

public:
  Complex(double re, double im) {
    this->re = re;
    this->im = im;
  }
  Complex &operator=(const Complex o) {
    this->re = o.re;
    this->im = o.im;

    return *this;
  }
  bool operator==(
      const Complex o) { // i overloaded the operational operator == so that my
    // function will also work for the Complex type
    if (this->re == o.re && this->im == o.im)
      return true;
    else
      return false;
  }
  Complex operator+(const Complex o) {
    return Complex(this->re + o.re, this->im + o.im);
  }
  friend ostream &operator<<(ostream &o, Complex c) {
    o << c.re << "+" << c.im << "i" << '\n';
    return o;
  }
};

template <typename T>
int array_search(T array[], int number, T element) { // the search function
  for (int i = 0; i < number; i++)
    if (array[i] == element)
      return i;
  return -1;
}

int main() { // testing using an array of ints,doubles, strings and Complex
             // instances
  int intarr[] = {1, 2, 3, 4, 5, 6};
  cout << array_search(intarr, 6, 1) << '\n';

  double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
  cout << array_search(darr, 6, 1.1) << '\n';

  string sarr[] = {"apple", "cherry", "orange"};
  string substr = "zebra";
  cout << array_search(sarr, 3, substr) << '\n';

  Complex carr[] = {Complex(1, 2), Complex(3, 4), Complex(-3, -5)};
  cout << array_search(carr, 3, Complex(1, 2)) << '\n';
  return 0;
}