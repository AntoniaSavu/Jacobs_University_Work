/*CH-230-A
a4_p10.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
void proddivpowinv(float a, float b, float *prod, float *div, float *pwr, float *invb)
{
    *prod = a * b;
    *div = a / b;
    *pwr = pow(a, b);
    *invb = 1 / b;
}

int main()
{
    float a, b, prod, div, pwr, invb;
    //I declared local variables that are "hosts" for the pointers
    //that the function calls for.
    //I could've also allocated on the heap for each pointer,
    //but I considered it unecessary in this instance.
    scanf("%f %f", &a, &b);
    proddivpowinv(a, b, &prod, &div, &pwr, &invb); //calling the function
    //printing out all the results:
    printf("The product: %f\n", prod);
    printf("The division: %f\n", div);
    printf("a b: %f\n", pwr);
    printf("1/b: %f\n", invb);

    return 0;
}