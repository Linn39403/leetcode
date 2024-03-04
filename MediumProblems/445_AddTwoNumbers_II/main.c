#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    You are given two non-empty linked lists representing two non-negative integers. 
    The most significant digit comes first and each of their nodes contains a single digit. \
    Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
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
    struct ListNode *next;
};

struct ListNode* createLLWithValues(int *array, int size)
{
    if(size == 0) return NULL;
    struct ListNode * L1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * Lans = L1;
    L1->val = array[0];
    for(int i=1; i<size; i++)
    {
        L1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        L1 = L1->next;
        L1->val = array[i];
    }
    L1->next = NULL;
    return Lans;
}

struct ListNode* createLLWithReverseValues(int *array, int size)
{
    if(size == 0) return NULL;
    struct ListNode * L1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * Lans = L1;
    L1->val = array[size-1];
    for(int i=size-2; i>-1; i--)
    {
        L1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        L1 = L1->next;
        L1->val = array[i];
    }
    L1->next = NULL;
    return Lans;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    int array1[10] = {0};
    int array2[10] = {0};
    int Ans[10] = {0};
    int idx1 = 0, idx2 = 0, iAns = 0;
    int itemp, carry = 0;
    //copy the list1 and list2 into arrays first
    do
    {
        array1[idx1++] = l1->val;
        l1 = l1->next;
    } while (l1 != NULL);
    do
    {
        array2[idx2++] = l2->val;
        l2 = l2->next;
    } while (l2 != NULL);
    idx1--; idx2--;
    //add the two arrays together
    do
    {
        int itemp = 0;
        if(idx1 > -1){
            itemp += array1[idx1];
        }
        if(idx2 > -1 ){
            itemp += array2[idx2];
        }
        itemp+=carry;
        carry = 0;
        if(itemp > 9){
            carry = 1;
            itemp -= 10;
        }
        Ans[iAns++] = itemp;
        idx1--;
        idx2--;
    } while (idx1 > -1 || idx2 > -1);
    if(carry){
        Ans[iAns++] = carry;
    }
    return createLLWithReverseValues(Ans,iAns);
}



void printLL(struct ListNode * LL)
{
    do{
        printf("%d->", LL->val);
        LL = LL->next;
    }while(LL != NULL);
    printf("NULL\n");
}

int main(void)
{   
    #if 0
    int arr1[] = {7,2,4,3};
    int arr2[] = {5,6,4};
    struct ListNode * L1 = createLLWithValues(arr1,4);
    struct ListNode * L2 = createLLWithValues(arr2,3);
    printLL(addTwoNumbers(L1,L2));
    
    int arr3[] = {0};
    struct ListNode * L3 = createLLWithValues(arr3,1);
    printLL(addTwoNumbers(L3,L3));
    #endif
    
    #if 0
    int arr1[] = {2,4,3};
    int arr2[] = {5,6,4};
    struct ListNode * L1 = createLLWithValues(arr1,3);
    struct ListNode * L2 = createLLWithValues(arr2,3);
    printLL(addTwoNumbers(L1,L2));
    #endif

    #if 1
    int arr1[] = {5};
    struct ListNode * L1 = createLLWithValues(arr1,1);
    printLL(addTwoNumbers(L1,L1));
    #endif

#if 0
    int arr1[] = {9,1,6};
    int arr2[] = {0};
    struct ListNode * L1 = createLLWithValues(arr1,3);
    struct ListNode * L2 = createLLWithValues(arr2,1);
    printLL(addTwoNumbers(L1,L2));
#endif
    return 0;
}


