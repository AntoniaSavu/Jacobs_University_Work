/*CH-230-A
a5_p8.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

void reading(int **a, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    //function that reads the elements of a matrix
}
void printing(int **a, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    //function that prints a matrix
}
void multiplication(int **a, int **b, int **c, int n, int m, int p)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            for (k = 0; k < m; k++)
                c[i][j] += a[i][k] * b[k][j];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    //function that multiplies 2 matrices
}
int main()
{
    int **m_A, **m_B, **m_C, n, m, p, i, j;
    scanf("%d %d %d", &n, &m, &p);
    m_A = (int **)malloc(sizeof(int *) * n);
    if (m_A == NULL)
        exit(1);
    for (i = 0; i < n; i++)
    {
        m_A[i] = (int *)malloc(sizeof(int) * m);
        if (m_A[i] == NULL)
            exit(1);
    }

    m_B = (int **)malloc(sizeof(int *) * m);
    if (m_B == NULL)
        exit(1);
    for (i = 0; i < m; i++)
    {
        m_B[i] = (int *)malloc(sizeof(int) * p);
        if (m_B[i] == NULL)
            exit(1);
    }

    m_C = (int **)malloc(sizeof(int *) * n);
    if (m_C == NULL)
        exit(1);
    for (i = 0; i < n; i++)
    {
        m_C[i] = (int *)malloc(sizeof(int) * p);
        if (m_C[i] == NULL)
            exit(1);
    }
    //dynamically allocating thee 3 matrices
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            m_C[i][j] = 0;
    //giving every element in the third matrix
    //the value 0 to ensure the smooth
    //application of the multiplication function
    reading(m_A, n, m);
    reading(m_B, m, p); //reading the elements of the 2 matrices
    printf("Matrix A:\n");
    printing(m_A, n, m);
    printf("Matrix B:\n");
    printing(m_B, m, n); //calling the functions to print the 2 matrices
    printf("The Multiplication result AxB:\n");
    multiplication(m_A, m_B, m_C, n, m, p); //calling the multiplication function
    for (i = 0; i < m; i++)
        free(m_A[i]);
    free(m_A);
    for (i = 0; i < p; i++)
        free(m_B[i]);
    free(m_B);
    for (i = 0; i < m; i++)
        free(m_C[i]);
    free(m_C); //freeing the allocated memory

    return 0;
}