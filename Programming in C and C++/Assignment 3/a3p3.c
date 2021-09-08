/*
CH-230-A
a3_p3.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/

float convert(int cm) //conversion function
{
    float km;
    km = cm / 100000.0;
    //making sure that the result will be a float
    //by adding .0 to the denominator
    return km;
}

#include <stdio.h>
int main()
{
    int cm;
    scanf("%d", &cm); //reading the integer
    printf("Result of conversion: %f\n", convert(cm));
    //calling the function directly in printf

    return 0;
}