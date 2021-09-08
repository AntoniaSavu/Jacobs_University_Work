/*
CH-230-A
a3_p7.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
void print_form(int n, int m, char c)
{
    int i, j;
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < m + i; j++)

            printf("%c ", c);
        // printing the character the right
        // amount of times using 2 fors

        printf("\n");
        //newlines essentially give the trapezoid form
    }
}
int main()
{
    int n, m;
    char c;
    scanf("%d %d", &n, &m);
    scanf("\n%c", &c);
    print_form(n, m, c); //calling function
    return 0;
}