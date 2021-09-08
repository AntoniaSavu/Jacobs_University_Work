/*
CH-230-A
a3_p2.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    char ch;
    int n, i = 0;
    scanf("%c", &ch); // reading the character
    scanf("%d", &n);  // reading n
    while (i <= n)
    //using a loop starting from 0, so that
    //ch itself is printed aswell
    {
        printf("%c\n", ch - i);
        i++;
    }
    return 0;
}