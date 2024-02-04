#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>


/*
    Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
    Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

    Constraints:

    >> 1 <= s.length <= 3 * 10^5
    >> s consists of digits, '+', '-', '(', ')', and ' '.
    >> s represents a valid expression.
    >> '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
    >> '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
    >> There will be no two consecutive operators in the input.
    >> Every number and running calculation will fit in a signed 32-bit integer.
*/

void myassert(int iResult, int iExpected, char * cPtrTestName);
#define DEBUG 1

#define STACK_MAX_SIZE 30
struct stk_str
{
    int top;
    int data[STACK_MAX_SIZE];
};

struct stk_str num_stk = {-1,0};
struct stk_str op_stk = {-1,0};


int top = -1;
int* stack_create() {
    int * stk = (int*)calloc(STACK_MAX_SIZE, sizeof(int));
    top = -1;
    return stk;
}

void stack_push(struct stk_str* obj, int val) {
  if(obj->top != STACK_MAX_SIZE - 1){
    obj->top++;
    obj->data[obj->top] = val;
  }
}

int stack_pop(struct stk_str* obj) {
    int iVal = -1;
    if(obj->top != -1){
        iVal = obj->data[obj->top];
        obj->top--;
    }
    return iVal;
}

int stack_peek(struct stk_str* obj) {
    int iVal = -1;
    if(obj->top != -1){
        iVal = obj->data[obj->top];
    }
    return iVal;
}


int stack_top(struct stk_str* obj) {
    int iVal = 0;
    if(obj->top != -1){
        iVal = obj->top;
    }
    return iVal;
}

int get_op_precdence(int operator)
{
    if(operator=='+' || operator == '-') return 1;
    return 2;
}

int calculate(char* s) 
{
    int s_len = strlen(s);
    int iAns = 0, iAns2, iAns3;

    char num_arr[10000] = {0};
    int num_arr_idx = 0;
    int i_temp = 0;
    char op_in_stack;
    for(int i=0; i<s_len; i++)
    {
        if(s[i] != ' ') //skip spaces
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {   
                if(num_arr_idx) //is it num string?
                {   //yes, so convert to interger and push it to the stack
                    i_temp = atoi(num_arr); //for debugging purpose
                    stack_push(&num_stk, i_temp);
                    num_arr_idx = 0;
                    memset(num_arr, 0, sizeof(num_arr)/sizeof(num_arr[0]));
                }   
                if(op_stk.top == -1) //is the opeator stack empty?
                {
                    stack_push(&op_stk,s[i]);
                }
                else
                {
                    //operator stack is not empty, we need to check what is the operator stored in the stack
                    //if current opeator precendece is smaller or equal to the operator in the stack, we need to remove the operator in the stack and calculate
                    //until the stack is empty or the precdence in the stack is smaller than input
                    switch(s[i]) //current opeartor
                    {
                        case '+': //precedence 1, we must calcaulate for all opeators in the opeator stack
                        case '-':
                            while(num_stk.top != -1 && op_stk.top != -1 && (get_op_precdence(s[i]) <= get_op_precdence(stack_peek(&num_stk)) ))
                            {
                                iAns3 = stack_pop(&num_stk);
                                iAns2 = stack_pop(&num_stk);
                                switch(stack_pop(&op_stk))
                                {
                                    case '+': 
                                        iAns = iAns2 + iAns3;
                                    break;
                                    case '-':
                                        iAns = iAns2 - iAns3;                                
                                    break;
                                    case '*': 
                                        iAns = iAns2 * iAns3;                                
                                    break;
                                    case '/':
                                        iAns = iAns2 / iAns3;                                
                                    break;
                                }
                                stack_push(&num_stk, iAns); //push the calculated result to the num stack
                            }
                            stack_push(&op_stk,s[i]); //store the current operator to the operator stack for all the opeators
                        break;

                        case '*': //precedence 2
                        case '/':
                            op_in_stack = stack_peek(&op_stk);
                            switch(op_in_stack)
                            {
                                case '*': //same precdence in the stack, we have to calculate
                                case '/':
                                stack_pop(&op_stk); //pop out without reading, cos we have known what it is
                                iAns3 = stack_pop(&num_stk);
                                iAns2 = stack_pop(&num_stk);
                                if(op_in_stack=='*')
                                {
                                    iAns = iAns2 * iAns3;
                                }
                                else
                                {
                                    iAns = iAns2 / iAns3;
                                }
                                stack_push(&num_stk, iAns); //push the calculated result to the num stack
                                break;
                            }
                            stack_push(&op_stk,s[i]); //store the current operator to the operator stack 
                        break;

                        default: break;
                    }
                }        
            }
            else if(s[i] >= '0' && s[i] <= '9')//numbers
            {
                num_arr[num_arr_idx++] = s[i];
            }
            else //'(' or ')' 
            {
                stack_push(&op_stk,s[i]);
            }
        }
    }
    if(num_arr_idx)
    {
        iAns = atoi(num_arr);
    }
    if(op_stk.top != -1)
    {
        while(op_stk.top != -1)
        {
            switch(stack_pop(&op_stk))
            {
                case '+':
                iAns = stack_pop(&num_stk) + iAns;
                break;
                case '-':
                iAns = stack_pop(&num_stk) - iAns;
                break;
                case '*':
                iAns = stack_pop(&num_stk) * iAns;
                break;
                case '/':
                iAns = stack_pop(&num_stk) / iAns;
                break;
            }
        }
    }
    return iAns;
}


int main(void)
{
    myassert(calculate("1+1"), 2, "Test Case 0");
    myassert(calculate("2-1+2"), 3, "Test Case 1");
    myassert(calculate("(1+(4+5+2)-3)+(6+8)"), 23, "Test Case 2");
    myassert(calculate("1-(     -2)"), 3, "Test Case 3");
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

