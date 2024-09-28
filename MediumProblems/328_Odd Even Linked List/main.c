/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 *Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
 */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode 
{
    int val;
    struct  ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) 
{
    if(head == NULL || head->next == NULL ) return head;
    struct ListNode * oddList = head;
    struct ListNode * evenList = head->next;
    struct ListNode * evenHeadList = evenList;

    while(evenList != NULL && evenList->next != NULL)
    {
        oddList->next = evenList->next;
        oddList = oddList->next;

        evenList->next = oddList->next;
        evenList = evenList->next;
    }
    oddList->next = evenHeadList;
    return head;
}

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

void printLL(struct ListNode * LL)
{
    do{
        printf("%d->", LL->val);
        LL = LL->next;
    }while(LL != NULL);
    printf("NULL\n");
}

int main (void)
{
    #if 1
    int arr1[] = {1,2,3,4,5};
    struct ListNode *L1 = createLLWithValues(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printLL(oddEvenList(L1));

    int arr2[] = {2,1,3,5,6,4,7};
    struct ListNode *L2 = createLLWithValues(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printLL(oddEvenList(L2));
#endif
    int arr3[] = {1};
    struct ListNode *L3 = createLLWithValues(arr3, sizeof(arr3) / sizeof(arr3[0]));
    printLL(oddEvenList(L3));

    return 0;
}
