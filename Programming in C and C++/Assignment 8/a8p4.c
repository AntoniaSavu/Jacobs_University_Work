/*CH-230-A
a8_p4.h
Antonia Savu
asavu@jacobs-university.de
*/
struct stack
{
    unsigned int count;
    int array[12];
};
void push(struct stack *, int);
void pop(struct stack *);
void empty(struct stack *);
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

int main()
{
    struct stack *stack;
    stack = (struct stack *)malloc(sizeof(struct stack));
    //allocating memory for a stack
    if (stack == NULL)
        exit(1);
    stack->count = 0;
    char c;
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