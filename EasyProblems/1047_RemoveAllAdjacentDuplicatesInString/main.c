#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void myassert(char * result, char * expected, char * printStr);
/*
   Given two integer arrays pushed and popped each with distinct values, 
   return true if this could have been the result of a sequence of push 
   and pop operations on an initially empty stack, or false otherwise.
*/
#define MAX  100000
typedef struct{
    char *val;
    int top;
}stack_type;

stack_type stack;

void initStack(stack_type *st)
{
    st->top = -1;
    st->val = (char*)calloc(MAX,sizeof(char));
}

// return -1 if stack is full
int push(stack_type *st, char val)
{
    if(st->top == MAX - 1 ){
        return -1;
    }
    st->top++;
    st->val[st->top] = val;
    return 0;
}

// return -1 if there is stack underflow 
char pop(stack_type *st)
{
    char iAns;
    if( st->top == -1){
        return -1;
    }
    iAns = st->val[st->top];
    st->top--;
    return iAns;
}

// return -1 if stack is empty
char peek(stack_type *st)
{
    if( st->top == -1){
        return -1;
    }
    return st->val[st->top];
}

char * removeDuplicates(char * s)
{
    initStack(&stack);
    int iStrLen = strlen(s);
    char * cptrAns = calloc(iStrLen,sizeof(char));
    if(iStrLen==1){
        cptrAns[0] = s[0];
        return cptrAns;
    }
    
    for(int i=0;i<iStrLen;i++){
        if(i<iStrLen+1 && s[i]==s[i+1]){
            i++; //don't push the adj chars
        }else{
            if(stack.top > -1 && peek(&stack) == s[i]){
                pop(&stack);
            }else{
                push(&stack,s[i]);
            }
        }
    }

    {
        //reverse the result
        int i = stack.top;
        while(stack.top > -1){
            cptrAns[i--] = pop(&stack);
        }
    }
    return cptrAns;
}
/*

*/

char ans1[] = "ca";
char ans2[] = "ay";
char ans3[] = "ehflcjmgljhbjecdikajfdmadcfdiahkaglkeifdcljcgmfgflijgihiejmfgekaljkmfkdfikjgkb";
int main(void)
{        
    myassert(removeDuplicates("abbaca"),ans1,"Tese Case 1.");
    myassert(removeDuplicates("azxxzy"),ans2,"Tese Case 2.");
    myassert(removeDuplicates("ehflcjmgljhbjecdbbikajfdmabbdcfdiahkaglkeibbfdcljcghhmfgfmfjjfaamlijgihiejmccfiigekaljkmfklldfikjgkb"),ans3,"Tese Case 3.");
    return 0;
}

void myassert(char * result, char * expected, char * printStr)
{
    if(strcmp(result, expected) != 0)
    {
        printf("ERROR: Expected %s, result =  %s, %s\r\n",expected, result, printStr);
    }
    else
    {
        printf("OK: Expected %s, result =  %s\r\n",expected, result);
    }
}
