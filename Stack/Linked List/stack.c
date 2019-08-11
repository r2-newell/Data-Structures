#include "stack.h"
#include <stdio.h>
#include <stdlib.h> 

int main()
{
    Stack stack; 
    if(!initializeStack(&stack))
            return -1; 
    int counter = 65; 
    while(counter < 91)
    {
        printf("\n%c", counter); 
        push(&stack, counter); 
        counter++; 
    }

    printf("\n-----------------------\n"); 
    char letter; 
    while(!isStackEmpty(&stack))
    {
        pop(&stack, &letter); 
        printf("\n%c", letter);
    }
    printf("\n");
    clearStack(&stack); 
    return 0; 
}

/*
 *Initializes stack and returns true if successful
 * */
bool initializeStack(Stack *stack)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value as stack.");
        return false; 
    }
    stack->top = NULL; 
    stack->size = 0; 
    return true; 
}

/*
 *Straightforward function. Even a baby can comprehend this.
 * */

bool isStackEmpty(const Stack *stack)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value as stack.");
        return false; 
    }
return  stack->top == NULL? true : false; 
}

/*
 *Pushes an element on top of the stack and updates size which is basically tells us how much element is in the stack.
 * */
bool push(Stack *stack, char letter)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value as stack.");
        return false; 
    }
    
    node *temp = calloc(1, sizeof(node));
    if(temp == NULL)
        return false; 

    temp->data = letter; 
    temp->next = stack->top; 
    stack->top = temp; 
    stack->size++; 
    return true;
}

/*
 *Pops the stack top and adjusts the stack to next element in it. 
 *
 * */
void pop(Stack *stack, char *letter)
{
    if(stack == NULL || letter == NULL)
    {
        printf("\nYou passed a null value as stack.");
        return; 
    }

    if(isStackEmpty(stack))
            letter = NULL; 
    else
           *letter = (stack->top)->data; 
    node *top = stack->top; 
    stack->top = stack->top->next; 
    free(top); 
    stack->size--; 
}

/*
 *Returns stack top
 * */
node *peek(const Stack *stack)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value as stack.");
        return NULL; 
    }
return stack->top; 
}

/*
 *Frees all memory allocated to stack
 * */
void clearStack(Stack *stack)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value as stack.");
        return; 
    }

    char letter; 
    while(!isStackEmpty(stack))
            pop(stack, &letter); 
}
