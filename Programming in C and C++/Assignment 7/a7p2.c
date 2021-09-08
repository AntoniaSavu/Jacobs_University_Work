/*CH-230-A
a7_p2.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

struct list
{
    char info;
    struct list *prev;
    struct list *next;
    //the doubly linked list
};

struct list *head = NULL;
struct list *prev = NULL;
struct list *next = NULL;
struct list *last = NULL;

struct list *push_front(struct list *my_list, char value)
{ //function that adds an element at the beginning of a list
    struct list *newel;
    newel = (struct list *)malloc(sizeof(struct list));
    //allocating memory
    if (newel == NULL)
    {
        printf(" Error allocating memory");
        return my_list;
    }
    else
    {
        newel->info = value;
        newel->next = my_list;
        //linking the element to the list
        newel->prev = NULL;
        //making sure it is the first
        if (my_list != NULL)
            my_list->prev = newel;
        my_list = newel;
    }

    return my_list;
}

void print_list(struct list *my_list)
{ //function to print the list
    struct list *p;
    for (p = my_list; p; p = p->next)
        printf("%c ", p->info);
}

void print_backwards(struct list *my_list)
{ //function to print list in reverse
    struct list *temp;
    if (my_list == NULL)
        return;
    for (temp = my_list; temp->next != NULL; temp = temp->next)
    {
    } //first iterating through the entire list so we can get to
    //the last element
    while (temp)
    {
        printf("%c", temp->info);
        temp = temp->prev;
        //printing backwards
    }
    printf("\n");
}
struct list *delet(struct list *my_list, char value)
{ //function that will remove all the elements with the given value
    struct list *temp = my_list;
    struct list *p;
    int element = 0;
    while (temp)
    {

        if (temp->info == value)
        {
            element++;
            //taking a counter in order to
            //be able to verify if the element
            //even existed in the list

            if (temp->prev != NULL && temp->next != NULL)
            { // if the element is found in the middle
                //we remove it and link its previous with
                //its next
                p = temp->prev;
                p->next = temp->next;
                p = temp->next;
                p->prev = temp->prev;
                free(temp); //then actually deleting temp
            }
            else if (temp->next == NULL)
            { //if the element is at the end
                //simply overwrite it with its previous
                //then also freeing the memory
                p = temp->prev;
                p->next = NULL;
                free(temp);
            }
            else if (temp->prev == NULL)
            { //if the element is at the beginning
                //similar to when it is at the end
                p = temp->next;
                p->prev = NULL;
                free(temp);
                my_list = p; //making my_list
                //point to the first element
            }
            else if (temp->prev == NULL && temp->next == NULL)
                return NULL;
        }
        temp = temp->next;
    }
    if (element == 0) //checking if we ever found the element
        printf("The element is not in the list!\n");
    return my_list;
}

void dispose_list(struct list *my_list)
{ //frees the list
    struct list *nextelem;
    nextelem = my_list;
    while (nextelem != NULL)
    {
        struct list *temp = nextelem->next;
        free(nextelem);
        nextelem = temp;
    }
}

int main()
{

    int input;
    char value;
    int flag = 1;

    while (flag)
    {
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            scanf(" %c", &value);
            head = push_front(head, value);
            break;
        case 2:
            scanf(" %c", &value);
            head = delet(head, value);

            break;
        case 3:
            print_list(head);
            break;
        case 4:
            print_backwards(head);

            break;
        case 5:
            dispose_list(head);
            flag = 0;
            break;
        }
    }
    return 0;
}