/*
CH-230-A
a4_p1.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#define _USE_MATH_DEFINES //getting PI value
#include <stdio.h>
#include <math.h>
int main()
{
    float lower_limit, upper_limit, step, i;
    scanf("%f%f%f", &lower_limit, &upper_limit, &step);
    //reading the lower limit,upper limit and the step
    for (i = lower_limit; i <= upper_limit; i += step)
    { //for loop using the input
        printf("%f %f %f\n", i, i * i * M_PI, 2 * i * M_PI);
        //printing out the perimeter and area using the correct formulas
    }

    return 0;
}