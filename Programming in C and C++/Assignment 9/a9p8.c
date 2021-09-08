/*CH-230-A
a9_p8.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void subtractmax(int *a)
{
    int max = INT_MIN;
    for (int i = 0; a[i]; i++)
        if (a[i] > max)
            max = a[i];
    for (int i = 0; a[i]; i++)
        a[i] -= max;
    //function that subtracts the maximum
    //value from all the elements in the array
    //i didnt know if the max value has to be subtracted from itself aswell,
    //but if it doesn't, only thing that needs to be added is
    //if(a[i]!=max) before line 17
}
void deallocate(int *a)
{
    delete (a);
    //deallocating using delete
}
int main()
{
    int n, i;
    cin >> n;
    int *a = new int(n); //dynamically allocating array
    for (i = 0; i < n; i++)
        cin >> a[i]; //reading the elements of the array
    cout << "Before subtracting: ";
    for (i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n'
         << "After subtracting: ";
    subtractmax(a); //calling the function
    for (i = 0; i < n; i++)
        cout << a[i] << ' ';
    deallocate(a); //deallocating
    return 0;
}