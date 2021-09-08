/*CH-230-A
a5_p5.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
double product(double *v, double *w, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i] * w[i];
    return sum;
    //function for scalar product
}
void largest(double *v, int n)
{
    double largest = v[0];
    int p = 0;
    for (int i = 1; i < n; i++)
        if (v[i] > largest)
        {
            largest = v[i];
            p = i;
        }
    printf("The largest = %lf\n", largest);
    printf("Position of largest = %d\n", p);
    //function for largest value
    //and its position
}
void smallest(double *v, int n)
{
    double smallest = v[0];
    int p = 0;
    for (int i = 1; i < n; i++)
        if (v[i] < smallest)
        {
            smallest = v[i];
            p = i;
        }
    printf("The smallest = %lf\n", smallest);
    printf("Position of smallest = %d\n", p);
    //function for smallest value
    //and its position
}
int main()
{
    double *v, *w;
    int n;
    scanf("%d", &n);
    v = (double *)malloc(sizeof(double *) * n);
    w = (double *)malloc(sizeof(double *) * n);
    //dynamically allocating the vectors
    if (v == NULL)
        exit(1);
    if (w == NULL)
        exit(1);
    for (int i = 0; i < n; i++)
        scanf("%lf", &v[i]); //reading the elements
    for (int i = 0; i < n; i++)
        scanf("%lf", &w[i]); //of the two vectors

    printf("Scalar product=%lf\n", product(v, w, n));
    smallest(v, n);
    largest(v, n);
    smallest(w, n);
    largest(w, n);
    //calling all the functions for both v and w
    free(v); //freeing the allocated memory
    free(w);
    return 0;
}