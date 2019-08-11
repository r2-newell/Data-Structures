/*
 *Author: Romario Newell
  Date: August 10, 2019
 * 
 * */

/*
 *This program aims to demonstrate the usage of a stack in parenthesis balancing. A stack can be used to implement an algorithm that can
  check whether an expression is fully parenthesized. Many algorithms text books and theory of computation text books mention
  the algorithm. An explanation of the algorithm can be seen in Mark Allen Weiss text book Data Structures and Algorithms in C++ on pages 
  104 - 105.Essentially, we can describe the algorithm as impelementing a pushdown automata. The algorithm is as follows, simply push only
  left parenthesis '(' on the stack from the input stream. When we encounter a right parenthsis then we pop until we ecounter the
  corresponding left parenthsis. If the stack becomes empty and we still have input then an error occurred. The same follows if stack is 
  not empty and we still have input. Finally, if none of the previous conditions occur then the expression is balanced. Let's go implement   this bitch.  
 * */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h" 

int balance(const char *); 

int main()
{
        char expression[256]; 
        printf("\nPlease enter an expression: "); 
        scanf("%s", expression); 
        balance(expression); 
        if(balance(expression) == 0)
                printf("\nBalanced\n"); 
        else    printf("\nNot balanced.\n");
    return 0; 
}

int balance(const char *str)
{
    Stack stack; 
    initializeStack(&stack); 
    push(&stack, '$'); //Helps us with the starting of the algorithm. A little place holder.
    char token = '\0'; 

    while(*str && !isStackEmpty(&stack))
    {
        if(*str == '(' || *str == '{' || *str == '[')
                push(&stack, *str);
        else if(*str == ')' || *str == '}' || *str == ']')
        {
            pop(&stack, &token);
            if(token == '(' && *str != ')')
                    break;
            else if(token == '{' && *str != '}')
                    break;
            else if(token == '[' && *str != ']')
                    break;
        }
        str++;
    }
    
    char *top;
    if(*str)
    {
        clearStack(&stack); 
        return -1; 
    }
    
    top = peek(&stack);
    if(top != NULL && *top != '$') 
    {
        clearStack(&stack); 
        return -1;  
    }

    clearStack(&stack);
    return 0;
}

