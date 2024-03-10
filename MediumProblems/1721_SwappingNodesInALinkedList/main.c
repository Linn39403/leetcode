#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    You are given the head of a linked list, and an integer k.
    Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
    Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 10^5
    0 <= Node.val <= 100
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

struct ListNode* swapNodes(struct ListNode* head, int k) 
{
    int arr[100000] = {0};
    int arr_idx = 0;
    struct ListNode * LL = head;
    do{
        arr[arr_idx++] = LL->val;
        LL = LL->next;
    }while(LL != NULL);
    if(arr_idx == 1) return head;
    LL = head;
    int temp = arr[k-1];
    arr[k-1] = arr[arr_idx - k];
    arr[arr_idx - k] = temp;
    return createLLWithValues(arr,arr_idx);
}


void printLL(struct ListNode * LL)
{
    if(LL == NULL)
    {
        printf("NULL\n");    
        return;
    }
    do{
        printf("%d->", LL->val);
        LL = LL->next;
    }while(LL != NULL);
    printf("NULL\n");
}

int main(void)
{   

    int arr1[] = {1,2,3,4,5};
    struct ListNode * L1 = createLLWithValues(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printLL(swapNodes(L1,2));

    int arr2[] = {7,9,6,6,7,8,3,0,9,5};
    struct ListNode * L2 = createLLWithValues(arr2,sizeof(arr2)/sizeof(arr2[0]));
    printLL(swapNodes(L2,5));
#if 0    
    int arr3[] = {1,2};
    struct ListNode * L3 = createLLWithValues(arr3,sizeof(arr3)/sizeof(arr3[0]));
    printLL(removeNthFromEnd(L3,1));

    int arr4[] = {1,2};
    struct ListNode * L4 = createLLWithValues(arr4,sizeof(arr4)/sizeof(arr4[0]));
    printLL(removeNthFromEnd(L4,2));

    int arr5[] = {1,2,3};
    struct ListNode * L5 = createLLWithValues(arr5,sizeof(arr5)/sizeof(arr5[0]));
    printLL(removeNthFromEnd(L5,3));
#endif
    return 0;
}


