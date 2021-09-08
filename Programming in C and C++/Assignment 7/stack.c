/*CH-230-A
a8_p4.c
Antonia Savu
asavu@jacobs-university.de
*/
#include "stack.h" //including the header
#include <stdio.h>
#include <stdlib.h>

void push(struct stack *stack, unsigned int value)
{ //function that checks if there is stack overflow
    if (stack->count == 12)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        stack->array[++stack->count] = value % 2;
        //printf("%d", value % 2); //modified this in order
        //to store binary.
    } //otherwise pushes an element
}
