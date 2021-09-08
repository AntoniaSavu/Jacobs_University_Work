/*
CH-230-A
a2_p1.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/


#include <stdio.h>
int main()
{
    double x,y;
    int a,b,sum_of_integers,product_of_integers; 
    char m,n; 
    scanf("%lf", & x);
    scanf("%lf", & y);
    printf("sum of doubles=%lf\n", x+y);
    printf("difference of doubles=%lf\n",x-y);
    printf("square=%lf\n",x*x);

    scanf("%d %d", &a, &b);
    sum_of_integers=a+b;
    product_of_integers=a*b;
    printf("sum of integers=%d\n",sum_of_integers);
    printf("product of integers=%d\n",product_of_integers);

    

    scanf( "\n%c %c", &m, &n);

    printf("sum of chars=%d\n",m+n);
    printf("product of chars=%d\n",m*n);
    printf("sum of chars=%c\n",m+n);
    printf("product of chars=%c\n",m*n);
    

    return 0;
}