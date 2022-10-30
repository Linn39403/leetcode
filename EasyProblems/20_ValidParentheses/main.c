#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/
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

bool isValid(char * s)
{
    bool bAns = false;
    int iLen = strlen(s);
    struct Stack* stack = createStack(iLen);
    if(iLen < 2) return bAns;
    for(int i = 0 ; i < iLen; i++)
    {
        switch(s[i])
        {
            case '(': push(stack,'('); break;
            case '[': push(stack,'['); break;
            case '{': push(stack,'{'); break;

            case ')':
                if(peek(stack) == '('){
                    pop(stack);
                }else{
                    return bAns;
                }
            break; 

            case ']':
                if(peek(stack) == '['){
                    pop(stack);
                }else{
                    return bAns;
                }
            break;
            case '}':
                if(peek(stack) == '{'){
                    pop(stack);
                }else{
                    return bAns;
                }
            break;
        }
    }
    if(isEmpty(stack)==true){
        bAns = true;
    }
    return bAns;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName);
int main(void)
{        
    myassert(isValid("()"),true,"Test Case 1");
    myassert(isValid("()[]{}"),true,"Test Case 2");
    myassert(isValid("(]"),false,"Test Case 3");
    return 0;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName)
{
    if(bResult != bExpected)
    {
        printf("%s. ERROR: Expected %d, result =  %d\r\n",cPtrTestName, bExpected, bResult);
    }
    else
    {
        printf("%s. OK: Expected %d, result =  %d\r\n",cPtrTestName, bExpected, bResult);
    }
}

