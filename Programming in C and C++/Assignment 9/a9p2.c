/*CH-230-A
a9_p2.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    double x;
    char s[500];
    cin >> n >> x; // reading the int and the double
    cin.get();
    cin.getline(s, 500); //reading the string
    for (int i = 0; i < n; i++)
        //printing the double and the string n times
        cout << s << ":" << x << '\n';

    return 0;
}