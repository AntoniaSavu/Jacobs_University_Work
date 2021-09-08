/**
 CH-230-A
a8_p2.h
Antonia Savu
asavu@jacobs-university.de
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int Item;

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
    int items;
} Queue;

/**
 * @brief Initializes a queue
 *
 * Initializes a newly allocated queue. It does not cleanup an already
 * used queue. Use empty_queue() for cleaning up an already used queue.
 *
 * @param pq The pointer to the queue structure.
 */

void initialize_queue(Queue *pq);

/**
 * @brief Tests whether the queue is full.
 *
 * Tests whether the queue is full, i.e., the number of elements in
 * the queue has reached MAXQUEUE.
 *
 * @param pq The pointer to the queue structure.
 *
 * @return 1 if the queue is full, 0 otherwise
 */

int queue_is_full(const Queue *pq);

/**
 * @brief Tests whether the queue is empty.
 *
 * Tests whether the queue is full, i.e., the number of elements in
 * the queue has reached 0. A newly initialized queue is empty.
 *
 * @param pq The pointer to the queue structure.
 *
 * @return 1 if the queue is empty, 0 otherwise.
 */

int queue_is_empty(const Queue *pq);

/**
 * @brief Returns the number of items in the queue.
 *
 * Returns the number of items currently in the queue.
 *
 * @param pq The pointer to the queue structure.
 *
 * @return The returned value will be between 0 and MAXQUEUE.
 */

int queue_item_count(const Queue *pq);

/**
 * @brief Add a new item to the queue.
 *
 * Add a new item to the queue.
 *
 * @param item The item to add to the queue.
 * @param pq The pointer to the queue structure.
 *
 * @return Returns the value 0 if successful and the value -1 in case
 * an error occurred (e.g., the queue is full or memory allocation
 * failed).
 */

int enqueue(Item item, Queue *pq);

/**
 * @brief Remove an item from the queue.
 *
 * Remove an item from the queue.
 *
 * @param pitem The pointer to memory where the item can be returned.
 * @param pq The pointer to the queue structure.
 *
 * @return Returns the value 0 if successful and the value -1 in case
 * an error occurred (e.g., the queue is empty).
 */

int dequeue(Item *pitem, Queue *pq);

/**
 * @brief Empty the queue.
 *
 * Empty the queue by removing all stored items. This leaves the queue
 * in its initialized state so that the queue can be reused.
 *
 * @param pq The pointer to the queue structure.
 */

void empty_queue(Queue *pq);

void printq(Queue *pq);

#endif

#include <stdio.h>
#include <stdlib.h>

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
{
    struct node *printing;
    printf("content of the queue: ");
    for (printing = pq->front; printing != NULL; printing = printing->next)
        printf("%d ", printing->item);

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
int main()
{
    Queue line;
    Item temp;
    char ch;

    initialize_queue(&line);

    while (((ch = getchar()) != EOF) && (ch != 'q'))
    {
        switch (ch)
        {
        case 'a':
            printf("add int: ");
            scanf("%d", &temp);
            if (!queue_is_full(&line))
            {
                printf("Putting %d into queue\n", temp);
                enqueue(temp, &line);
            }
            else
                puts("Queue is full");
            break;

        case 'd':
            if (queue_is_empty(&line))
                puts("Nothing to delete!");
            else
            {
                dequeue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
            break;
        case 'p':
            printq(&line);
            break;
        default:
            printf("%d items in queue\n", queue_item_count(&line));
            puts("Type a to add, d to delete, p to print, q to quit:");
        }
    }
    empty_queue(&line);
    puts("Bye.");
    return 0;
}