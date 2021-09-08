/*
CH-230-A
a2_p8.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x); // reading the given number
    // A number is divisible by both 2 and 7 only if it is
    // divisible by 14.
    if (x % 14 == 0)
        printf("The number is divisible by 2 and 7\n");
    else
        printf("The number is NOT divisible by 2 and 7\n");
    return 0;
}
