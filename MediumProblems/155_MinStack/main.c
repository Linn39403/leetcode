#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.
*/
void myassert(int iResult, int iExpected, char * cPtrTestName);

#define STACK_MAX_SIZE 30000

typedef struct {
    int Val;
    int minVal;
} MinStack;

int top = -1;
MinStack* minStackCreate() {
    MinStack * stk = (MinStack*)calloc(STACK_MAX_SIZE, sizeof(MinStack));
    top = -1;
    return stk;
}

void minStackPush(MinStack* obj, int val) {
  if(top != STACK_MAX_SIZE - 1){
    top++;
    obj[top].Val = val;
    if(top == 0){       //initial stack pointer
        obj[top].minVal = val;
    }else{
        if(val < obj[top-1].minVal)
            obj[top].minVal = val;
        else
            obj[top].minVal = obj[top-1].minVal;
    }
  }
}

void minStackPop(MinStack* obj) {
    if(top != -1){
        top--;
    }
}

int minStackTop(MinStack* obj) {
    int iVal = 0;
    if(top != -1){
        iVal = obj[top].Val;
    }
    return iVal;
}

int minStackGetMin(MinStack* obj) {
    int iValMin = 0;
    if(top != -1){
        iValMin = obj[top].minVal;
    }
    return iValMin;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

int main(void)
{        
    MinStack * minStack =  minStackCreate();
    minStackPush(minStack,-2);
    minStackPush(minStack,0);
    minStackPush(minStack,-3);
    myassert(minStackGetMin(minStack),-3,"Test Case 1a."); // return -3
    minStackPop(minStack);
    myassert(minStackTop(minStack),0,"Test Case 1b");    // return 0
    myassert(minStackGetMin(minStack),-2,"Test Case 1c"); // return -2
    minStackFree(minStack);

    /*-------------------------------------------------*/
    minStack =  minStackCreate();
    minStackPush(minStack,-1);
    myassert(minStackTop(minStack),-1,"Test Case 2a");    // return -1
    myassert(minStackGetMin(minStack),-1,"Test Case 2b"); // return -1
    minStackFree(minStack);

    /*-------------------------------------------------*/    
    minStack =  minStackCreate();
    minStackPush(minStack,2);
    minStackPush(minStack,0);
    minStackPush(minStack,3);
    minStackPush(minStack,0);
    myassert(minStackGetMin(minStack),0,"Test Case 3a"); // return 0
    minStackPop(minStack);
    myassert(minStackGetMin(minStack),0,"Test Case 3b"); // return 0
    minStackPop(minStack);
    myassert(minStackGetMin(minStack),0,"Test Case 3c"); // return 0
    minStackPop(minStack);
    myassert(minStackGetMin(minStack),2,"Test Case 3d"); // return 2    

    /*-------------------------------------------------*/  
    minStack =  minStackCreate();
    minStackPush(minStack,-10);
    minStackPush(minStack,14);
    myassert(minStackGetMin(minStack),-10,"Test Case 3a"); // return -10
    myassert(minStackGetMin(minStack),-10,"Test Case 3b"); // return -10
    minStackPush(minStack,-20);
    myassert(minStackGetMin(minStack),-20,"Test Case 3c"); // return -20
    myassert(minStackGetMin(minStack),-20,"Test Case 3d"); // return -20    
    myassert(minStackTop(minStack),-20,"Test Case 3e"); // return -20
    myassert(minStackGetMin(minStack),-20,"Test Case 3f"); // return -20
    minStackPop(minStack);
    minStackPush(minStack,10);
    minStackPush(minStack,-7);
    myassert(minStackGetMin(minStack),-10,"Test Case 3g"); // return -10
    minStackPush(minStack,-7);
    minStackPop(minStack);
    myassert(minStackTop(minStack),-7,"Test Case 3h"); // return -20
    myassert(minStackGetMin(minStack),-10,"Test Case 3i"); // return -10
    minStackPop(minStack);
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

