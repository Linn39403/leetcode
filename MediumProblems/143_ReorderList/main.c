#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.
    The number of nodes in the list is in the range [1, 5 * 10^4].
    1 <= Node.val <= 1000
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) 
{
    //int arr[50000] = {0};
    int arr[10] = {0};
    int arr_idx = 0;
    struct ListNode * LL = head;
    int i;
    do{
        arr[arr_idx++] = LL->val;
        LL = LL->next;
    }while(LL != NULL);

    if(arr_idx == 1) return;
    for(i = 0; i < arr_idx / 2; i ++ )
    {
        head->val = arr[i];
        head = head->next;
        head->val = arr[arr_idx - i - 1];
        head = head->next;
    }
    if(arr_idx & 0x01) //odd
    {
        head->val = arr[i];
        head = head->next;
    }
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

    int arr1[] = {1,2,3,4,5};
    struct ListNode * L1 = createLLWithValues(arr1,5);
    reorderList(L1);
    printLL(L1);
    
    //int arr3[] = {0};
    //struct ListNode * L3 = createLLWithValues(arr3,1);
    //printLL(addTwoNumbers(L3,L3));

    

    return 0;
}


