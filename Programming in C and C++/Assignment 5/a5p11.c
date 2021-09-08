/*CH-230-A
a5_p11.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int prime(int n, int d)
{
    if (n == 1)
        return 0;
    else if (d == 1) /* addressing the base cases*/
        return 1;
    else if (n % d == 0)
        return 0;
    else

        return prime(n, d - 1); //function calling itself
}
int main()
{
    int x;
    scanf("%d", &x);
    if (prime(x, x / 2))
        //it is redundant to start checking from d=x,
        // d=x/2 will suffice
        printf("%d is prime\n", x);
    else
        printf("%d is not prime\n", x);

    return 0;
}