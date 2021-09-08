/*
CH-230-A
a2_p6.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    double x, y, *ptr_one, *ptr_two, *ptr_three;
    scanf("%lf%lf", &x, &y);
    ptr_one = &x;
    ptr_two = &x;
    //Making the first two pointers point at x
    ptr_three = &y;
    // And third at y
    printf("the address of ptr_one=%p\n", ptr_one);
    printf("the address of ptr_two=%p\n", ptr_two);
    printf("the address of ptr_three=%p\n", ptr_three);
    return 0;
}