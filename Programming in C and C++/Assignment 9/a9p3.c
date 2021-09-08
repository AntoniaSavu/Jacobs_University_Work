/*CH-230-A
a9_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
using namespace std;

float absol(float a)
{
    if (a >= 0)
        return a;
    else
        return -a;
    //function that returns the absolute value
}

int main()
{
    float x;
    cin >> x; //reading the float value
    cout << "The absolute value is " << absol(x);
    //calling the function
    return 0;
}