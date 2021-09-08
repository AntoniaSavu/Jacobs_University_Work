/*CH-230-A
a9_p4.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
using namespace std;
int mycount(int a, int b)
{
    return b - a;
    //mycount for integers, computing the difference
}
int mycount(char c, char s[])
{
    int count = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            count++;
    return count;
    //mycount for strings, computing
    //how many occurences c has in s
}
int main()
{
    int a, b;
    char c, s[500];
    cin >> a >> b >> c; //reading the two ints and the char
    cin.get();
    cin.getline(s, 500);           //reading the strings
    cout << mycount(a, b) << '\n'; //showcasting the functions
    cout << mycount(c, s);
    return 0;
}