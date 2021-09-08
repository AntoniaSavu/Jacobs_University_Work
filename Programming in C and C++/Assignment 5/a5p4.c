/*CH-230-A
a5_p4.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
void divby5(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] /= 5;
    //dividing the elements by 5
}
int main()
{
    int n;
    float *arr;
    scanf("%d", &n);
    arr = (float *)malloc(sizeof(float *) * n);
    //dynamically allocating array
    if (arr == NULL)
        exit(1);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    //reading the elements
    printf("Before:\n");
    for (int i = 0; i < n; i++)
        printf("%0.3f ", arr[i]);
    //printing the elements
    printf("\n");
    printf("After:\n");
    divby5(arr, n); //calling the function
    for (int i = 0; i < n; i++)
        printf("%0.3f ", arr[i]);
    //printing the modified elements
    printf("\n");
    free(arr); //freeing memory

    return 0;
}