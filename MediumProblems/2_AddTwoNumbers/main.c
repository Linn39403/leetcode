#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode * next;
}ListNode;
void myassert(struct ListNode * sPtrResult, struct ListNode *  sPtrExpected, char * cPtrStr);
struct ListNode * CreateLinkList(int iSize)
{
    struct ListNode * sPtr;
    struct ListNode * sPtrHead;
    sPtr = (struct ListNode*)malloc(sizeof(struct ListNode));
    sPtrHead = sPtr;
    for(int i=0; i < iSize - 1; i++)
    {
        sPtr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        sPtr = sPtr->next;
    }
    sPtr->next = NULL;
    return sPtrHead;
}

struct ListNode * CreateLinkListAndInit(int iSize, int * iPtrInitArray)
{
    struct ListNode * sPtr = CreateLinkList(iSize);;
    struct ListNode * sPtrHead;
    sPtrHead = sPtr;
    sPtr->val = iPtrInitArray[0];
    for(int i=1; i < iSize; i++)
    {
        sPtr->next->val = iPtrInitArray[i];
        sPtr = sPtr->next;
    }
    sPtr->next = NULL;
    return sPtrHead;
}

int GetLinkListLength(struct ListNode * sPtr)
{
    int iCnt = 0;
    do
    {
        iCnt ++ ;
        sPtr = sPtr->next;
    } while (sPtr);
    return iCnt;
}

void PrintLinkList(struct ListNode * sPtr)
{
    int iLinkListLength = GetLinkListLength(sPtr);
    for(int i = 0 ; i < iLinkListLength; i ++ )
    {
        printf("%d -> ", sPtr->val);
        sPtr = sPtr->next;
    }
    printf("NULL\r\n");
}

bool CompareLinkList(struct ListNode * sPtr1,struct ListNode * sPtr2)
{
    do
    {
        if(sPtr1->val != sPtr2->val)
        {
            return false;
        }
        sPtr1 = sPtr1->next;
        sPtr2 = sPtr2->next;
    } while (sPtr1);
    return true;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * sPtr = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * sHead = sPtr;
    struct ListNode * sTemp;
    int iCarry = 0;
    int iVar1,iVar2,iTemp;
    sPtr->next = NULL;
    iVar1 = l1->val; iVar2 = l2->val;
    do
    {
        iTemp = iVar1 + iVar2 + iCarry;
        sPtr->val = (iTemp)%10;
        iCarry = iTemp > 9 ? 1 : 0;
        iVar1 = 0; 
        iVar2 = 0;
        if(l1!=NULL)
        {
            l1 = l1->next;
            if(l1!=NULL)  iVar1 = l1->val;
        }
  
        if(l2!=NULL)
        {
            l2 = l2->next;
            if(l2!=NULL)  iVar2 = l2->val;
        }
        if( ( l1 != NULL || l2 != NULL ) || iCarry != 0 )   
        {
            sTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
            sTemp->next = NULL;
            sTemp->val = 0;
            sPtr->next = sTemp;
            sPtr = sPtr->next;
        }    
        else
        {
            sPtr->next = NULL;
        }
    }while(l1 != NULL || l2 != NULL);
    if(iCarry) sPtr->val += iCarry;
    return sHead;
}

int ArrayA1[3] = {2,4,3};
int ArrayA2[3] = {5,6,4};
int ArrayAAns[3] = {7,0,8};

int ArrayB1[7] = {9,9,9,9,9,9,9};
int ArrayB2[4] = {9,9,9,9};
int ArrayBAns[8] = {8,9,9,9,0,0,0,1};

struct ListNode * sPtr1, *sPtr2, *sPtr3;
int main(void)
{
    sPtr1 = CreateLinkListAndInit(3, ArrayA1);
    sPtr2 = CreateLinkListAndInit(3, ArrayA2);
    sPtr3 = CreateLinkListAndInit(3, ArrayAAns);
    myassert(addTwoNumbers(sPtr1,sPtr2), sPtr3, "Test1" );
    free(sPtr1); free(sPtr2); free(sPtr3); 

    sPtr1 = CreateLinkListAndInit(7, ArrayB1);
    sPtr2 = CreateLinkListAndInit(4, ArrayB2);
    sPtr3 = CreateLinkListAndInit(8, ArrayBAns);
    myassert(addTwoNumbers(sPtr1,sPtr2), sPtr3, "Test2" );
    free(sPtr1); free(sPtr2); free(sPtr3); 

    #if 0
    PrintLinkList(sPtr1);
    PrintLinkList(sPtr2);
    PrintLinkList(sPtr3);
    PrintLinkList(addTwoNumbers(sPtr1,sPtr2));
    #endif

    return 0;
}


void myassert(struct ListNode * sPtrResult, struct ListNode *  sPtrExpected, char * cPtrStr)
{
    if(CompareLinkList(sPtrResult,sPtrExpected) == false)
    {
        printf("%s ERROR: Expected ",cPtrStr ); // result =  %d\r\n"
        PrintLinkList(sPtrExpected);
        printf(", Result ");
        PrintLinkList(sPtrResult);   
        printf("\r\n");   
    }
    else
    {
        printf("%s OK: Expected ",cPtrStr ); // result =  %d\r\n"
        PrintLinkList(sPtrExpected);
        printf(", Result ");
        PrintLinkList(sPtrResult);   
        printf("\r\n");  
    }
    free(sPtrResult);
}