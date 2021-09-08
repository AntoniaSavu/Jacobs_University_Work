#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
struct list
{
    int info;
    struct list *next;
};
struct list *push_front(struct list *my_list, int value)
{
    struct list *newel;
    newel = (struct list *)malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf(" Error allocating memory \n");
        return my_list;
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}
struct list *remove(struct list *my_list)
{
    struct list *alpha;
    alpha = my_list;
    alpha = alpha->next;
    free(my_list);
    my_list = alpha;
    return my_list;
}
struct list *push_back(struct list *my_list, int value)
{
    struct list *cursor, *newel;
    cursor = my_list;
    newel = (struct list *)malloc(sizeof(struct list));
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
{
    struct list *p;
    for (p = my_list; p; p = p->next)
    {
        printf("%d\n", p->info);
    }
}
void dispose_list(struct list *my_list)
{
    struct list *nextelem;
    while (my_list != NULL)
    {
        nextelem = my_list->next;
        free(my_list);
        my_list = nextelem;
    }
}

int main()
{
    struct list *my_list = NULL;
    my_list = push_front(my_list, 34);
    my_list = push_front(my_list, 18);
    my_list = push_back(my_list, 56);
    print_list(my_list);
    my_list = remove(my_list);
    printf("\n\n");
    print_list(my_list);
    dispose_list(my_list);

    return 0;
}