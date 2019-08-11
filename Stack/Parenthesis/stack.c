#include "stack.h"
#include <stdio.h>
#include <stdlib.h>



/*
 *Initializes stack. Upon success we return a true, false upon failure
 * */
bool initializeStack(Stack *stack)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value for stack.");
        return false; 
    }

    const int SIZE  = 2; 
    stack->data = calloc(SIZE, sizeof(char)); 
    if(stack->data == NULL)
    {
        printf("\nCould not allocate memory for stack."); 
        return false; 
    }

    stack->top = -1; 
    stack->size = SIZE; 
    return true; 
}

/*
 *Test whether stack is empty or not. Returns true when stack is empty, false otherwise.
 * */
bool isStackEmpty(const Stack *stack)
{

    if(stack == NULL)
    {
        printf("\nYou passed a null value for stack.");
        return false; 
    }
    return stack->top == -1? true : false; 
}

/*
 *Pushes an element and returns true when successful, false otherwise
 * */
bool push(Stack *stack, char letter)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value for stack.");
        return false; 
    }
    
    /*
     *Checks if stack is full below.  When the stack is full stack->top == stack->size -1.
     * */
    if(stack->top == stack->size -1)
            if(!resizeStack(stack, stack->size * 2))/*resizes the stack and test whether the resize was successful*/
                    return false;
    stack->data[++stack->top] = letter; 
    return true;
}

/*
 *Pops an element from the stack. Puts into a variable by the pointer letter
 * */
void pop(Stack *stack, char *letter)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value for stack.");
        return; 
    } if(isStackEmpty(stack))
    {   
        printf("\nThe stack is empty. Can not pop from an empty stack.");
        return;
    }if(letter == NULL)
    {
        printf("\nYou passed a null value for letter."); 
        return; 
    }

    *letter = stack->data[stack->top--];
    if(stack->top < stack->size / 4)
            resizeStack(stack, stack->size / 4);
}

/*
 *Returns the top most element.
 * */
char *peek(const Stack *stack)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value for stack.");
        return NULL; 
    }

    return isStackEmpty(stack)? NULL : stack->data + stack->top;
}

/*
 *Resizes the stack by either doubling or shrinking to quarter the size. The idea for this is taken from 
  Robert Sedgewick and Kevin Wayne Algorithms book.
 * */
bool resizeStack(Stack *stack, int size)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value for stack.");
        return false; 
    }
    
    char *data = calloc(size, sizeof(char)); 
    if(data == NULL)
            return false; 
    for(int counter = 0; counter <= stack->top; counter++)
            data[counter] = stack->data[counter];
    free(stack->data); 
    stack->data = data; 
    stack->size = size; 
    return true; 
}

/*
 *
 *Returns used memory
 * */
void clearStack(Stack *stack)
{
    if(stack == NULL)
    {
        printf("\nYou passed a null value for stack.");
        return; 
    }
    free(stack->data); 
}
