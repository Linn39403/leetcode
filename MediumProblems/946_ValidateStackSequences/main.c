#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
   Given two integer arrays pushed and popped each with distinct values, 
   return true if this could have been the result of a sequence of push 
   and pop operations on an initially empty stack, or false otherwise.
*/
void myassert(bool bResult, bool bExpected, char * cPtrTestName);
#define MAX  1000
int stack[MAX] , top = -1;

// return -1 if stack is full
int push(int *st, int val)
{
    if(top == MAX - 1 ){
        return -1;
    }else{
        top++;
        st[top] = val;
    }
    return 0;
}

// return -1 if there is stack underflow 
int pop(int *st)
{
    int iAns;
    if( top == -1){
        return -1;
    }else{
        iAns = st[top];
        top--;
        return iAns;
    }
}

// return -1 if stack is empty
int peek(int *st)
{
    if( top == -1){
        return -1;
    }else{
        return st[top];
    }    
}

void initStack()
{
    memset(stack,0,sizeof(int)*MAX);
    top=-1;
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    initStack();
    int j = 0;
    for(int i=0; i<pushedSize;i++)
    {
        push(stack,pushed[i]);
        while((top!=-1) && peek(stack) == popped[j])
        {
            pop(stack);
            j++;
        }
    }
    return (top==-1);
}

int iArrPush1[] = {1,2,3,4,5};
int iArrPop1[]  = {4,5,3,2,1};

int iArrPush2[] = {1,2,3,4,5};
int iArrPop2[]  = {4,3,5,1,2};

int iArrPush3[] = {0,2,1};
int iArrPop3[]  = {0,1,2};

int iArrPush4[] = {2,1,0};
int iArrPop4[]  = {2,1,0};

int iArrPush5[] = {1,0,2};
int iArrPop5[]  = {2,1,0};

int iArrPush6[] = {2,1,0};
int iArrPop6[]  = {1,2,0};
int main(void)
{        
    myassert(validateStackSequences(iArrPush1,5,iArrPop1,5),true,"Test Case 1");
    myassert(validateStackSequences(iArrPush2,5,iArrPop2,5),false,"Test Case 2");
    myassert(validateStackSequences(iArrPush3,3,iArrPop3,3),true,"Test Case 3");
    myassert(validateStackSequences(iArrPush4,3,iArrPop4,3),true,"Test Case 4");
    myassert(validateStackSequences(iArrPush5,3,iArrPop5,3),false,"Test Case 5");
    myassert(validateStackSequences(iArrPush6,3,iArrPop6,3),true,"Test Case 6");
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

