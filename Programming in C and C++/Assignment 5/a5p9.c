/*CH-230-A
a5_p9.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

void reading(int ***a, int n, int m, int p)
{
    int i, j, k;
    for (i = 0; i < p; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < m; k++)
                scanf("%d", &a[i][j][k]);
    //function that reads the elements of the matrix
}
void printing(int ***a, int n, int m, int p)
{
    int i, j, k;
    for (k = 0; k < m; k++)
    {
        printf("Section %d:\n", k + 1);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < p; j++)
                printf("%d ", a[i][j][k]);
            printf("\n");
        }
    }
    //function that prints the sections
}

int main()
{
    int row, column, depth, ***a;
    scanf("%d %d %d", &row, &column, &depth);

    a = (int ***)malloc(row * sizeof(int **));
    if (a == NULL)
        exit(1);
    for (int i = 0; i < row; i++)
    {
        a[i] = (int **)malloc(column * sizeof(int *));
        if (a[i] == NULL)
            exit(1);
        for (int j = 0; j < column; j++)
        {
            a[i][j] = (int *)malloc(depth * sizeof(int));
            if (a[i][j] == NULL)
                exit(1);
        }
    }                                //allocating the memory
    reading(a, row, column, depth);  //calling the
    printing(a, row, column, depth); //two functions
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            free(a[i][j]);
        }

        free(a[i]);
    }
    free(a); //freeing the memory

    return 0;
}