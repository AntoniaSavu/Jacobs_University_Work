/*CH-230-A
a5_p6.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int count(float *a, int n)
{
    int c = 0, *ptr_c = &c;
    float *i;
    for (i = a; i < a + n; i++)
    { //iterating through using pointer
        if (*i >= 0)
            c++;
        else

            break;
    }
    return *ptr_c;
    //function that counts the elements
    //before the first negative value
}
int main()
{
    int n;
    scanf("%d", &n);
    float *a;
    a = (float *)malloc(sizeof(float) * n);
    //dynamically allocating array
    if (a == NULL)
        exit(1);
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]); //reading the elements
    printf("Before the first negative value: %d elements\n", count(a, n));
    //calling the function
    free(a); //freeing the allocated memory
    return 0;
}