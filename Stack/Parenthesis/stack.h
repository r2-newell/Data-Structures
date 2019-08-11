#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h> 
/*Author: Romario Newell*/
/*Date: July 20, 2019*/
/*Resizable array implementation of the stack*/

typedef struct 
{
        char *data;/*stack of characters*/
        int top;/*top of stack*/ 
        int size;/*current size of stack*/
}Stack;

/*Stack Operations*/

bool initializeStack(Stack *);/*initializes stack and returns true when successful*/
bool isStackEmpty(const Stack *);/*returns true when stack is empty*/
bool push(Stack *, char);/*pushes a character onto the stack*/
void pop(Stack *, char *);/*pops a character from the stack*/
char *peek(const Stack *);/*returns a pointer to the stack top. Null means stack is empty*/
void clearStack(Stack *);/*returns memory to heap*/
bool resizeStack(Stack *, int);/*resizes the stack*/

#endif
