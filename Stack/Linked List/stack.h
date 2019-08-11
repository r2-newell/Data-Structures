#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

/*
 *Author: Romario Newell
  Date: July 20, 2019
 * 
 * */

/*
 *Linked list implementation of a stack
 * 
 * */

typedef struct node
{
    char data;/*data part of node*/
    struct node *next;/*points to the next element within the stack*/
}node; 

typedef struct
{
    node *top;/*points to the top of the stack.*/ 
    int size;/*size of the stack*/ 
}Stack;

/*Stack Operations*/
bool initializeStack(Stack *);/*initializes stack, returns true when successful*/
bool isStackEmpty(const Stack *);/*returns true when stack is empty*/
bool push(Stack *, char);/*pushes a character*/
void pop(Stack *, char *);/*pops a character from stack*/
node *peek(const Stack *);/*returns the stack top*/
void clearStack(Stack *);/*returns memory allocated*/

#endif  
