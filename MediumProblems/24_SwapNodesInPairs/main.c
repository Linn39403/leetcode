#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct ListNode* nextPair = curr->next->next;
        struct ListNode* second = curr->next;

        second->next = curr;
        curr->next = nextPair;
        if (prev != NULL) {
            prev->next = second;
        }

        prev = curr;
        curr = nextPair;
    }

    return newHead;
}

int main(void)
{        
    
    int array1[] = {1,2,3,4,5,6,7,8,9,10};
    struct ListNode * LL1 = createLLWithValues(array1,sizeof(array1)/sizeof(array1[0]));
    printLL(swapPairs(LL1));
#if 0
    int array2[] = {1,1,1,2,3};
    struct ListNode * LL2 = createLLWithValues(array2,sizeof(array2)/sizeof(array2[0]));
    printLL(deleteDuplicates(LL2)); 

    int array3[] = {1,2, 2};
    struct ListNode * LL3 = createLLWithValues(array3,sizeof(array3)/sizeof(array3[0]));
    printLL(deleteDuplicates(LL3));

    int array4[]= {1,1};
    struct ListNode * LL4 = createLLWithValues(array4,sizeof(array4)/sizeof(array4[0]));
    printLL(deleteDuplicates(LL4));
#endif
    return 0;
}


