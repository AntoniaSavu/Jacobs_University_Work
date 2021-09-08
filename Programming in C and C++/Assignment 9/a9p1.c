/*CH-230-A
a9_p1.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
using namespace std;

int main()
{
    char country[500];         //declaring a string
    cin.getline(country, 500); //reading input from keyboard
    cout << "The country is: " << country;

    return 0;
}