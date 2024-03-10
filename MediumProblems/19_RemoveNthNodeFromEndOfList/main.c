#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    Given the head of a linked list, remove the nth node from the end of the list and return its head.
    Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int arr_idx = 0;
    int remove_idx;
    struct ListNode * LL = head;
    do{
        arr_idx++;
        LL = LL->next;
    }while(LL != NULL);
    LL = head;
    if(arr_idx == 1 && n == 1){
        head = NULL;
        return head;
    }else if(arr_idx == n){
        head = LL->next;
        return head;
    }
    remove_idx = arr_idx - n;
    for(int i=1; i < arr_idx;i++)
    {
        if(i==remove_idx){
            struct ListNode * Ltemp = LL;
            Ltemp = Ltemp->next;
            Ltemp = Ltemp->next;
            LL->next = Ltemp;
        }else{
            LL = LL->next;
        }
    }
    return head;
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
    printLL(removeNthFromEnd(L1,2));
    
    int arr2[] = {1};
    struct ListNode * L2 = createLLWithValues(arr2,sizeof(arr2)/sizeof(arr2[0]));
    printLL(removeNthFromEnd(L2,1));

    int arr3[] = {1,2};
    struct ListNode * L3 = createLLWithValues(arr3,sizeof(arr3)/sizeof(arr3[0]));
    printLL(removeNthFromEnd(L3,1));

    int arr4[] = {1,2};
    struct ListNode * L4 = createLLWithValues(arr4,sizeof(arr4)/sizeof(arr4[0]));
    printLL(removeNthFromEnd(L4,2));

    int arr5[] = {1,2,3};
    struct ListNode * L5 = createLLWithValues(arr5,sizeof(arr5)/sizeof(arr5[0]));
    printLL(removeNthFromEnd(L5,3));
    return 0;
}


