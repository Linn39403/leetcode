#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    Given the head of a singly linked list, return the middle node of the linked list.
    If there are two middle nodes, return the second middle node.

    Constraints:

    * The number of nodes in the list is in the range [1, 100].
    * 1 <= Node.val <= 100
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

struct ListNode* middleNode(struct ListNode* head) 
{
    struct ListNode * fast = head, * slow = head;

    while(fast && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    
}

int main(void)
{        
    
    int array1[] = {1,2,3,4,5};
    struct ListNode * LL1 = createLLWithValues(array1,sizeof(array1)/sizeof(array1[0]));
    printLL(middleNode(LL1));

    int array2[] = {1,2,3,4,5,6};
    struct ListNode * LL2 = createLLWithValues(array2,sizeof(array2)/sizeof(array2[0]));
    printLL(middleNode(LL2));
    
    return 0;
}


