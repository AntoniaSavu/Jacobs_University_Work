/*CH-230-A
a5_p9.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

void reading(int ***xoy, int n, int m, int p)
{

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {

                scanf("%d", &xoy[i][j][k]);
            }
        }
    }
    //function that reads the elements of the
    //matrix
}

void printing(int ***xoy, int n, int m, int p)
{
    // function that prints
    //the sections
    for (int k = 0; k < m; k++)
    {
        printf("Section %d:\n", k + 1);
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < p; j++)
            {

                printf("%d ", xoy[i][j][k]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int ***a, depth, row, column;

    scanf("%d %d %d", &depth, &row, &column);

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
    }
    // allocating the memory

    //calling the functions:
    reading(a, row, column, depth);

    printing(a, row, column, depth);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            free(a[i][j]);
        }

        free(a[i]);
    }
    free(a); //freeing the allocated memory
    return 0;
}
