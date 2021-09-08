/*
CH-230-A
a1_p4.c
Antonia Savu    
asavu@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    int x=17,y=4,sum,product,difference,remainder_of_division;
    float division=(float)x/(float)y;
     sum=x+y;
     product=x*y;
     difference=x-y;
     remainder_of_division=x%y;
    printf("x=%d\n",x);
     printf("y=%d\n",y);
     printf("sum=%d\n",sum);
     printf("product=%d\n",product);
     printf("difference=%d\n",difference);
     printf("division=%lf\n",division);
     printf("remainder of division=%d\n",remainder_of_division);
     
    return 0;
}