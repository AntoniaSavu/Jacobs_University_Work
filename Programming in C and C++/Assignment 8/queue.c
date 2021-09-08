/**
 CH-230-A
a8_p3.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
void initialize_queue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
    return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
    return pq->items;
}

int enqueue(Item item, Queue *pq)
{

    if (queue_is_full(pq))
        return -1; //checking if the queue is already full

    struct node *add;
    add = (struct node *)malloc(sizeof(struct node));
    //allocating memory
    if (add == NULL)
        return -1;
    add->item = item;
    add->next = NULL; ///adding the element at the end,
    //hence next=null
    if (queue_is_empty(pq))
        pq->front = add;
    //checking if the queue is empty and we should
    //consider the added node as the front of the queue
    else

        pq->rear->next = add;
    pq->rear = add;
    pq->items++;

    return 0;
}

int dequeue(Item *pitem, Queue *pq)
{ //function that removes the first node
    struct node *rem;
    if (queue_is_empty(pq))
        return -1; //checking if the list is empty
    *pitem = pq->front->item;
    rem = pq->front;             //the node we need to remove
    pq->front = pq->front->next; //making the front
    //of the queue the second item
    free(rem);   // freeing the memory
    pq->items--; //decreasing the number of items in the queue
    if (pq->items == 0)
        pq->rear = NULL;
    return 0;
}

void printq(Queue *pq)
{ //function that prints the queue
    struct node *printing;
    printf("content of the queue: ");
    for (printing = pq->front; printing != NULL; printing = printing->next)
        printf("%d ", printing->item);
    //looping through every node and printing it

    printf("\n");
}

void empty_queue(Queue *pq)
{
    Item dummy;
    while (!queue_is_empty(pq))
    {
        dequeue(&dummy, pq);
    }
}