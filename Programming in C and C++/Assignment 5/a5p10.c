/*CH-230-A
a5_p10.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
void print_numbers(int n)
{
    if (n == 1) //addressing the base case
        printf("%d ", n);
    else
    {
        printf("%d ", n);
        print_numbers(n - 1); //function calling itself
    }
}
int main()
{
    int x;
    scanf("%d", &x);
    print_numbers(x); //calling the function

    return 0;
}