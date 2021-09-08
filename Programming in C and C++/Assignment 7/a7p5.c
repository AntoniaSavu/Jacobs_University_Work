/*CH-230-A
a7_p5.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void quicksort(int *a, int n, int (*func)(const void *a, const void *b))
{ //quicksort function which takes a function pointer
    //as one of the arguments
    qsort(a, n, sizeof(int), func);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int compare_ascending(const void *a, const void *b)
{ //function that sorts the array ascending
    return (*(int *)a - *(int *)b);
}
int compare_descending(const void *a, const void *b)
{ //function that sorts the array descending
    return (*(int *)b - *(int *)a);
}
int main()
{
    int *a, n, i;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    //allocating memory for an array
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    //reading the elements

    char c;
    int aux = 1;
    while (aux)
    {

        scanf("%c", &c);
        switch (c) //switch instruction
        {
        case 'a':
            quicksort(a, n, compare_ascending);
            //calling the function using the ascending
            //pointer function
            break;
        case 'd':
            quicksort(a, n, compare_descending);
            //calling the function using the descending
            //pointer function
            break;
        case 'e':
            aux = 0; //breaking the infinite loop
            break;
        default:
            break;
        }
    }

    free(a); //freeing the allocated memory
    return 0;
}