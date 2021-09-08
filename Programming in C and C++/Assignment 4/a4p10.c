/*CH-230-A
a4_p10.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
void proddivpowinv(float a, float b, float *prod, float *div4, float *pwr, float *invb)
{
    *prod = a * b;
    *div4 = a / b;
    *pwr = pow(a, b);
    *invb = 1 / b;
}

int main()
{
    float a, b, *prod, *div4, *pwr, *invb;
    scanf("%f %f", &a, &b);
    //proddivpowinv(a, b, prod, div4, pwr, invb);
    //printf("The product: %f\n", *prod);
    //printf("The division: %f\n", *div4);
    //printf("a b: %f\n", *pwr);
    // printf("1/b: %f\n", *invb);

    return 0;
}