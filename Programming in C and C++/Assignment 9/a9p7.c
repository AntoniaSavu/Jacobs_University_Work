/*CH-230-A
a9_p7.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
using namespace std;
void swapping(int &a, int &b) //using reference
{
    int c = a;
    a = b;
    b = c;
    //function that swaps ints
}
void swapping(float &x, float &y) //using reference
{
    float c = x;
    x = y;
    y = c;
    //function that swaps floats
}
void swapping(const char *&c, const char *&t) //using reference
{
    const char *p;
    p = c;
    c = t;
    t = p;
    //function that swaps chars
}

int main(void)
{ //the main given
    int a = 7, b = 15;
    float x = 3.5, y = 9.2;
    const char *str1 = "One";
    const char *str2 = "Two";
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    swapping(a, b);
    swapping(x, y);
    swapping(str1, str2); //calling the three functions
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    return 0;
}