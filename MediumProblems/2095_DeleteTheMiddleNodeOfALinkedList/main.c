#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
    The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
    For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

    Constraints:
    The number of nodes in the list is in the range [1, 10^5].
    1 <= Node.val <= 10^5
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

struct ListNode* deleteMiddle(struct ListNode* head) 
{
    //int arr[100000] = {0};
    int arr[10] = {0};
    int arr_idx = 0;
    int middle;
    struct ListNode * LL = head;
    do{
        arr[arr_idx++] = LL->val;
        LL = LL->next;
    }while(LL != NULL);
    LL = head;
    if(arr_idx == 2){ 
        middle = 1;
    }
    else if(arr_idx == 1){
        head = NULL;
        return head;
    }
    else{
        middle = arr_idx/2;
    }
    for(int i=1; i < arr_idx;i++)
    {
        if(i==middle){
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
    do{
        printf("%d->", LL->val);
        LL = LL->next;
    }while(LL != NULL);
    printf("NULL\n");
}

int main(void)
{   

    int arr1[] = {1,3,4,7,1,2,6};
    struct ListNode * L1 = createLLWithValues(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printLL(deleteMiddle(L1));
    
    int arr2[] = {1,2,3,4};
    struct ListNode * L2 = createLLWithValues(arr2,sizeof(arr2)/sizeof(arr2[0]));
    printLL(deleteMiddle(L2));

    int arr3[] = {2,1};
    struct ListNode * L3 = createLLWithValues(arr3,sizeof(arr3)/sizeof(arr3[0]));
    printLL(deleteMiddle(L3));

    int arr4[] = {1};
    struct ListNode * L4 = createLLWithValues(arr4,sizeof(arr4)/sizeof(arr4[0]));
    printLL(deleteMiddle(L4));

    return 0;
}


