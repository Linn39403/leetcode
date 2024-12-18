#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list. Return the linked list sorted as well.
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

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL || head->next == NULL) return head;
    struct ListNode * curr = head;
    struct ListNode * newHead = NULL;
    struct ListNode * tail = NULL;
    while(curr)
    {
        if(curr->next && curr->val == curr->next->val)
        {  //found duplication
            while(curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
        } else {
          if (newHead == NULL) {
            newHead = curr;
            tail = newHead;
          } else {
            tail->next = curr;
            tail = tail->next;
          }
        }
        curr = curr->next;
    }
    if(tail) tail->next = NULL;
    return newHead;
}

int main(void)
{        
    
    int array1[] = {1,2,3,3,4,4,5};
    struct ListNode * LL1 = createLLWithValues(array1,sizeof(array1)/sizeof(array1[0]));
    printLL(deleteDuplicates(LL1));

    int array2[] = {1,1,1,2,3};
    struct ListNode * LL2 = createLLWithValues(array2,sizeof(array2)/sizeof(array2[0]));
    printLL(deleteDuplicates(LL2)); 

    int array3[] = {1,2, 2};
    struct ListNode * LL3 = createLLWithValues(array3,sizeof(array3)/sizeof(array3[0]));
    printLL(deleteDuplicates(LL3));

    int array4[]= {1,1};
    struct ListNode * LL4 = createLLWithValues(array4,sizeof(array4)/sizeof(array4[0]));
    printLL(deleteDuplicates(LL4));

    return 0;
}


