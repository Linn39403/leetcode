#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    Given head, the head of a linked list, determine if the linked list has a cycle in it.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
    Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.

    Constraints :
    * The number of the nodes in the list is in the range [0, 10^4].
    * -10^5 <= Node.val <= 10^5
    * pos is -1 or a valid index in the linked-list.
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

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode * fast = head;
    struct ListNode * slow = head;    
    if(head == NULL || head->next == NULL) return false;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main(void)
{   
#if 1
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 3;
    struct ListNode * node_2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = node_2;
    node_2->val = 2;
    struct ListNode * node_3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node_2->next = node_3;
    node_3->val = 0;
    struct ListNode * node_4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node_3->next = node_4;
    node_4->val = -4;
    node_4->next = node_2;
    detectCycle(head);
#endif

#if 0
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode * node_2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = node_2;
    node_2->val = 2;
    node_2->next = head;
    detectCycle(head);
#endif


    return 0;
}


