/*
CH-230-A
a1_p3.c
Antonia Savu    
asavu@jacobs-university.de
*/

#include <stdio.h> /// needs to have # before include 
int main( )
 {
float result; //∗ The result of the division ∗/
int a = 5;
double b = 13.5; //since this is not an integer, it should be declared as float or double
result = a / b;
printf("The result is %f\n", result); // used %f since it's not an integer(which what %d is used for)
return 0;
}