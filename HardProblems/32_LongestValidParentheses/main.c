#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * Given a string containing just the characters '(' and ')', 
 * return the length of the longest valid (well-formed) parentheses substring.
*/
#define max(a,b) (((a) > (b)) ? (a) : (b))
void myassert(int iResult, int iExpected, char * cPtrTestName);
// A structure to represent a stack
struct Stack {
    int top;
    unsigned int capacity;
    int* array;
};
  
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
  
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
  
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
  
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}
  
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
  
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

#define OPEN_P '('
#define CLOSE_P ')'

int longestValidParentheses(char * s)
{
    int iAns = 0;
    int iLen = strlen(s);
    struct Stack* stack = createStack(iLen);
    if(iLen < 2) return iAns;

    push(stack,-1);

    for(int i = 0 ; i < iLen ; i++)
    {
        if(s[i] == '(') push(stack,i);
        else{
            pop(stack);
            if(isEmpty(stack) == true){
                push(stack,i);
            }else{
                iAns = max(iAns, (i - peek(stack)));
            }
        }
    }

    return iAns;
}
int main(void)
{        
    myassert(longestValidParentheses("(()")                         ,2,"Test case.1");            
    myassert(longestValidParentheses(")()())")                      ,4,"Test case.2");
    myassert(longestValidParentheses("")                            ,0,"Test case.3");
    myassert(longestValidParentheses("((()))()")                    ,8,"Test case.4");
    myassert(longestValidParentheses("(()())")                      ,6,"Test case.5");  
    myassert(longestValidParentheses("()(((((((((()()")             ,4,"Test case.6");
    myassert(longestValidParentheses("(")                           ,0,"Test case.7");    
    myassert(longestValidParentheses("()(()")                       ,2,"Test case.8");
    myassert(longestValidParentheses(")()())()()(")                 ,4,"Test case.9");
    myassert(longestValidParentheses("((()))())")                   ,8,"Test case.10");
    myassert(longestValidParentheses("()(())")                      ,6,"Test case.11");
    myassert(longestValidParentheses(")()(((())))(")               ,10,"Test case.12"); 
    myassert(longestValidParentheses(")(((((()())()()))()(()))(")  ,22,"Test case.13");
    return 0;                       
}

void myassert(int iResult, int iExpected, char * cPtrTestName)
{
    if(iResult != iExpected)
    {
        printf("%s. ERROR: Expected %d, result =  %d\r\n",cPtrTestName, iExpected, iResult);
    }
    else
    {
        printf("%s. OK: Expected %d, result =  %d\r\n",cPtrTestName, iExpected, iResult);
    }
}

