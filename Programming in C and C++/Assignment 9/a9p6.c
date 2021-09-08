/*CH-230-A
a9_p6.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include <cstring>
using namespace std;
int myfirst(int a[])
{
    int x = -1;
    for (int i = 0; a[i]; i++)
        if (a[i] > 0 && a[i] % 2 == 0)
        { //returning the first positive and
            //even number
            x = a[i];
            break;
        }
    return x;
    //myfrist function for an int array
}
double myfirst(double a[])
{
    double x = -1.1;
    for (int i = 0; a[i]; i++)
        if (a[i] < 0 && (int)(a[i]) == a[i])
        { //returning the first element that is
            //an integer and that is negative
            x = a[i];
            break;
        }
    return x;
    //myfirst function for a double array
}
char myfirst(char s[])
{
    char c = '0';
    for (int i = 0; s[i]; i++)
        if (strchr("aeiouAEIOU", s[i]) == NULL)
        { //returning the first consonant
            c = s[i];
            break;
        }
    return c;
    //myfirst function for a string
}
int main()
{
    int n, a[500], m;
    double b[500];
    char s[500];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i]; //reading the int array
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i]; //reading the double array
    cin.get();
    cin.getline(s, 500);                       //reading the string
    cout << "Ints: " << myfirst(a) << '\n';    //showcasing
    cout << "Doubles: " << myfirst(b) << '\n'; //how the functions
    cout << "Strings: " << myfirst(s) << '\n'; //behave
    return 0;
}