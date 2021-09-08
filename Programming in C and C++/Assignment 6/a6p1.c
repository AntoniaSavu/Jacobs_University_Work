/*CH-230-A
a6_p1.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#define SWAP(A, B) \
    {              \
        A = A + B; \
        B = A - B; \
        A = A - B; \
    }
//swap macro
int main()
{
    int a, b;
    float c, d;
    scanf("%d %d %f %f", &a, &b, &c, &d); //reading the integers
    printf("After swapping:\n");
    SWAP(a, b); //utilizing the macro
    SWAP(c, d);
    printf("%d %d 0.6%f 0.6%f", a, b, c, d);
    //printing the swapped variables
    return 0;
}
