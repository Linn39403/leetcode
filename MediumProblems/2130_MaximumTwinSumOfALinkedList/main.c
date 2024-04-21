#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

    For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
    The twin sum is defined as the sum of a node and its twin.

    Given the head of a linked list with even length, return the maximum twin sum of the linked list.

    Constraints:

    * The number of nodes in the list is an even integer in the range [2, 10^5].
    * 1 <= Node.val <= 10^5
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
#define MAX(a,b)        ((a)>(b)?(a):(b))
int pairSum(struct ListNode* head) 
{
    struct ListNode * fast = head, * slow = head, * prev = NULL;
    struct ListNode * temp = NULL;
    int result = 0;

    while(fast && fast->next != NULL)
    {
        fast = fast->next->next;
        //reverse back the prev node 
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    //reach the half of the linked list
    
    while(slow)
    {
        result = MAX(result, slow->val + prev->val);
        slow = slow->next;
        prev = prev->next;
    }

    return result;
}

int main(void)
{        
    
    int array1[] = {5,4,2,1};
    printf("Max value %d\r\n",pairSum(createLLWithValues(array1,sizeof(array1)/sizeof(array1[0]))));
       
    return 0;
}


