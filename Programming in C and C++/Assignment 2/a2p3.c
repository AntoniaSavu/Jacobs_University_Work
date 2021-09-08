/*
CH-230-A
a2_p3.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    int weeks, days, hours, total_hours;
    // declaring the variables needed
    scanf("%d %d %d", &weeks, &days, &hours);
    total_hours = hours + days * 24 + weeks * 168;
    // computing total of hours
    printf("The total number of hours= %d", total_hours);
    // printing the total number of hourse

    return 0;
}