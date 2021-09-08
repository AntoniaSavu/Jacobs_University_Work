/*
CH-230-A
a3_p6.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>

float to_pounds(int kg, int g) //function for converting into pounds
{
    float pounds = 0;
    pounds += kg + g / 1000.0; //first converting everything to kgs
    pounds *= 2.2;             //then to pounds
    return pounds;
}

int main()
{
    int kg, g;
    scanf("%d %d", &kg, &g);
    printf("Result of conversion: %f\n", to_pounds(kg, g));
    // printing the result
    return 0;
}