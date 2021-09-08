/*CH-230-A
a4_p9.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int prodminmax(int a[], int n)
{ //function for the product of the smallest and largest element
    int i, largest = INT_MIN, smallest = INT_MAX;
    for (i = 0; i < n; i++)
    {
        if (a[i] > largest)
            largest = a[i];
        if (a[i] < smallest)
            smallest = a[i];
    }
    return smallest * largest;
}
int main()
{
    int n, i, *arr;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    //dynamically allocating array
    if (arr == NULL)
        exit(1);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The product:%d\n", prodminmax(arr, n)); ///calling the function

    return 0;
}