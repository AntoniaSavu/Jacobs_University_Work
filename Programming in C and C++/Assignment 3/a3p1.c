/*
CH-230-A
a3_p1.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    float x;
    int n;
    scanf("%f", &x);
    while (1) //infinite loop, exits on break
    {
        scanf("%d", &n); //reading n
        if (n > 0)
            //checking for positive condition
            break;
        // if it is fulfilled, exit lloop using break
        else
            printf("Input is invalid, reenter value\n");
        //otherwise reenter n, loop continues
    }
    while (n) //loop for printing x n times
    {
        printf("%f\n", x);
        n--;
    }

    return 0;
}