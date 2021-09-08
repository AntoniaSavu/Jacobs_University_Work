/*
CH-230-A
a3_p10.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
float product(float a, float b)
{
    return a * b;
}
void productbyref(float a, float b, float *p)
{
    float x = a * b;
    p = &x;
    printf("Value of the product using the second function: %f\n", *p);
}
void modifybyref(float *a, float *b)
{
    *a += 3;  //adding 3 and 11
    *b += 11; // using pointers
}

int main()
{
    float a, b, p;
    float *ptr_a, *ptr_b;
    scanf("%f %f", &a, &b);
    ptr_a = &a; //making the 2 pointers
    ptr_b = &b; // point to a and b
    printf("Product using the first function: %f\n", product(a, b));
    //calling the first function
    productbyref(a, b, &p);    //calling the second function
    modifybyref(ptr_a, ptr_b); // calling the third function
    printf("Changing variable a thorugh pointer :%f\n", *ptr_a);
    printf("Changing variable b thorugh pointer :%f\n", *ptr_b);

    return 0;
}