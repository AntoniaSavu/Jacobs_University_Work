/*CH-230-A
a6_p3.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#define min2(a, b) ((a) < (b) ? (a) : (b))
//helper macro that finds the minimum of two numbers
#define min(a, b, c) (min2(min2((a), (b)), (c)))
//macro that finds the minimum of three numbers
#define max2(a, b) ((a) > (b) ? (a) : (b))
//similar to the two macros above
#define max(a, b, c) (max2(max2((a), (b)), (c)))
#define mid_range(a, b, c) ((min(a, b, c) + max(a, b, c)) / 2.0)
//macro which determines the mid-range of three values
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    float d = mid_range(a, b, c); //computing the mid-range
    printf("The mid-range is: %0.6f\n", d);
    return 0;
}
