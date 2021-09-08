/*CH-230-A
a6_p4.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#define INTERMEDIATE

int main()
{
    int n, *a, *b, i, s = 0;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n); //allocating memory
    b = (int *)malloc(sizeof(int) * n); //for the two vectors
    if (a == NULL)
        exit(1);
    if (b == NULL)
        exit(1);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]); //reading the values for
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]); //the two vectors
    for (i = 0; i < n; i++)
        s += a[i] * b[i];
#if defined(INTERMEDIATE) // macro which prints the intermediat values
    printf("Intermediate values are:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i] * b[i]);
#endif
    printf("The scalar product is: %d\n", s);
    free(a); //freeing the
    free(b); //allocated memory
    return 0;
}
