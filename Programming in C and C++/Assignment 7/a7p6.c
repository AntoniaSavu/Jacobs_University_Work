/*CH-230-A
a7_p6.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct person
{
    char name[30];
    int age;
}; // the struct we are working with
void bubblesort(struct person *a, int n,
                int (*comp)(const struct person *person1,
                            const struct person *person2))
{ //bubblesort function which takes a function pointer as argument
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < n - 1; i++)
            if (comp(&a[i + 1], &a[i]) < 0) //using the function pointer
            {
                struct person temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
                swapped = 1;
            }
    } while (swapped);
}
int compare_name(const struct person *person1, const struct person *person2)
{ // function that compares the people based on their name first
    int str_cmp = strcmp(person1->name, person2->name);

    int age_cmp;
    if (person1->age < person2->age)
        age_cmp = -1;
    else
    {
        if (person2->age < person1->age)
            age_cmp = 1;
        else
            age_cmp = 0;
    }

    if (str_cmp != 0)
        return str_cmp;
    else

        return age_cmp;
}

int compare_age(const struct person *person1, const struct person *person2)
{ // function that compares the people based on their age first
    int str_cmp = strcmp(person1->name, person2->name);
    int age_cmp;
    if (person1->age < person2->age)
        age_cmp = -1;
    else
    {
        if (person2->age < person1->age)
            age_cmp = 1;
        else
            age_cmp = 0;
    }

    if (age_cmp != 0)
        return age_cmp;
    else

        return str_cmp;
}
int main()
{
    int i, n;
    struct person *a;
    scanf("%d", &n);
    a = (struct person *)malloc(sizeof(struct person) * n);
    //dynamically allocating an array
    if (a == NULL)
        exit(1);
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i].name);
        scanf("%d", &a[i].age);
        //reading the elements of the struct
    }
    bubblesort(a, n, compare_name);
    //calling the bubblesort based on name
    //with the help of the function pointer
    for (i = 0; i < n; i++)
    {
        printf("{%s, ", a[i].name);
        printf("%d}; ", a[i].age);
        //printing the array
    }
    printf("\n");
    bubblesort(a, n, compare_age);
    //calling the bubblesort based on age
    //with the help of the function pointer
    for (i = 0; i < n; i++)
    {
        printf("{%s, ", a[i].name);
        printf("%d}; ", a[i].age);
        //printing the array
    }

    free(a); //freeing the allocated memory
    return 0;
}