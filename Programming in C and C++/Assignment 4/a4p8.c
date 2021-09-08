/*CH-230-A
a4_p8.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
void matrixform(int arr[31][31], int n)
{ //function for printing the input as a matrix
    printf("The entered matrix is:\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);

        printf("\n");
    }
}
void underdiagonal(int arr[31][31], int n)
{ //function printing the values underneath the secondary diagonal
    printf("Under the secondary diagonal:\n");
    for (int i = 1; i < n; i++)
        for (int j = n - i; j < n; j++)
            printf("%d ", arr[i][j]);
    printf("\n");
}

int main()
{
    int n;
    int a[31][31];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]); //reading the elements
    matrixform(a, n);              //calling the two functions
    underdiagonal(a, n);

    return 0;
}
