/*CH-230-A
a8_p4.c
Antonia Savu
asavu@jacobs-university.de
*/
#include "stack.h" //including the header
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct stack *stack;
    stack = (struct stack *)malloc(sizeof(struct stack));
    //allocating memory for a stack
    if (stack == NULL)
        exit(1);
    stack->count = 0;
    unsigned int x;
    scanf("%u", &x);
    unsigned int a = x;
    printf("The binary representation of %u is ", a);
    while (x)
    {
        push(stack, x);
        x /= 2; //dividing so we can apply the
        //agorithm for division by 2
    }
    for (int i = stack->count; i > 0; i--)
        printf("%d", stack->array[i]); //reversing the stack so
    //it is in the correct order
    printf(".");
    free(stack);
    //freeing the allocated memory
    return 0;
}