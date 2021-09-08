/*CH-230-A
a7_p3.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
struct list
{
    int info;
    struct list *next;
    //defining an element of a list
};
struct list *push_front(struct list *my_list, int value)
{ //function that adds an element to the front
    struct list *newel;
    newel = (struct list *)malloc(sizeof(struct list));
    //dynamically allocating
    if (newel == NULL)
    {
        printf(" Error allocating memory \n");
        return my_list;
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}
struct list *rem(struct list *my_list)
{ //function that removes the first element of a list
    if (my_list == NULL)
        return my_list;
    //the if checks for the particular case
    //where we have an empty list
    //because otherwise we'd have
    //an illegal memory operation

    struct list *alpha;
    alpha = my_list;
    alpha = alpha->next;
    free(my_list);
    my_list = alpha;
    return my_list;
}
struct list *push_back(struct list *my_list, int value)
{ //function that adds an element to the back
    struct list *cursor, *newel;
    cursor = my_list;
    newel = (struct list *)malloc(sizeof(struct list));
    //dynamically allocating
    if (newel == NULL)
    {
        printf(" Error allocating memory \n");
        return my_list;
    }
    newel->info = value;
    newel->next = NULL;
    if (my_list == NULL)
        return newel;
    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = newel;
    return my_list;
}
void print_list(struct list *my_list)
{ //function that prints the list
    struct list *p;
    for (p = my_list; p; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}
void dispose_list(struct list *my_list)
{ //function that frees the memory allocated
    struct list *nextelem;
    while (my_list != NULL)
    {
        nextelem = my_list->next;
        free(my_list);
        my_list = nextelem;
    }
}