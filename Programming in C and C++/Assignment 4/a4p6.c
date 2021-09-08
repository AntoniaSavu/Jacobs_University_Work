/*CH-230-A
a4_p6.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void greatest_values(int a[], int n)
{ //function for the two greatest values
    int i, mvalue1 = INT_MIN, mvalue2 = INT_MIN;
    for (i = 0; i < n; i++)
    {
        if (a[i] > mvalue1)
        {
            mvalue2 = mvalue1;
            mvalue1 = a[i];
        }
        else
        {
            if (a[i] > mvalue2)
                mvalue2 = a[i];
        }
    }
    printf("The 2 greatest values are: %d and %d\n", mvalue1, mvalue2);
}
int main()
{
    int n, i, *dyn_array;
    scanf("%d", &n);
    dyn_array = (int *)malloc(sizeof(int) * n); //dynamically allocating array
    if (dyn_array == NULL)
        exit(1);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &dyn_array[i]);
    }
    greatest_values(dyn_array, n); //calling the function
    free(dyn_array);               //freeing the allocated memory

    return 0;
}