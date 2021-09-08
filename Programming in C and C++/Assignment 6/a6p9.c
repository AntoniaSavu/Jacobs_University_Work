/*CH-230-A
a6_p9.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct list
{
    int info;
    struct list *next;
    //defining an element of a list
};
int size = 0;
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
    size++;
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
    size--;
    return my_list;
}
struct list *reverse(struct list *my_list)
{ //function that reverses the items in a list
    struct list *previous = NULL;
    struct list *current = my_list;
    struct list *next = NULL;
    //using 3 pointers in order to swap the items
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    my_list = previous;
    return my_list;
}
struct list *insert(struct list *my_list, int position, int value)
{ //function that inserts an item at a given position
    int i;
    if (position < 0 || position > size)
        printf("Invalid position!"); //checking if the position is valid
    else
    {
        struct list *pointer, *adding;
        pointer = my_list;
        adding = (struct list *)malloc(sizeof(struct list));
        //dynamically allocating
        if (adding == NULL)
            printf("Error allocating memory\n");
        for (i = 0; i < position - 1 && pointer->next != NULL; i++)
            pointer = pointer->next; //iterating through the list until
        //right before we have to insert
        adding->info = value; //inserting
        adding->next = pointer->next;
        //also linking it to the next element so it is part of the list
        pointer->next = adding;
        size++;
    }
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
    size++;
    return my_list;
}
void print_list(struct list *my_list)
{
    struct list *p;
    for (p = my_list; p; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}
void dispose_list(struct list *my_list)
{ //printing the list
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
    struct list *mylist = NULL;
    int z = 1, x, y;
    char ch;
    while (z)
    { //infinite loop
        scanf("%c", &ch);
        switch (ch) //switch instruction
        {
        case 'b': //calling all the necessary functions for each case
            scanf("%d", &x);
            mylist = push_front(mylist, x);
            break;

        case 'a':
            scanf("%d", &x);
            mylist = push_back(mylist, x);
            break;
        case 'r':
            mylist = rem(mylist);
            break;
        case 'p':
            print_list(mylist);
            break;
        case 'q':
            dispose_list(mylist);
            z = 0;
            break;
        case 'R':
            mylist = reverse(mylist);
            break;
        case 'i':
            scanf("%d %d ", &x, &y);
            mylist = insert(mylist, x, y);
        default:
            break;
        }
    }

    return 0;
}