/*
CH-230-A
a1_p1.c
Antonia Savu    
asavu@jacobs-university.de
*/

#include <stdio.h>
int main() {
double result; //∗ The result of our calculation ∗/
result = (3 + 1) / 5.0;
 /* Despite 'result' being a double variable, 5 is an integer, and so the division result will be 
 an integer. By writing 5.0, the program sees the denominator as a double/float aswell, making the result correct*/
printf("The value of 4/5 is %lf\n", result);
return 0;
}
