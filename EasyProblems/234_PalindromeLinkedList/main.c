#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    Given the head of a singly linked list, return true if it is a palindrome
    or false otherwise.
    
    Constraints:

    * The number of nodes in the list is an even integer in the range [1, 10^5].
    * 0 <= Node.val <= 9
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

bool isPalindrome(struct ListNode* head) 
{
    struct  ListNode * fast = head, * slow = head;
    struct ListNode * temp = NULL, *prev = NULL;
    while (fast && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    while(slow)
    {
        //store half of the LL in rev way
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    //compare head with 2nd half reverse linked lise values
    while(prev)
    {
        if(head->val != prev->val)
        {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}

int main(void)
{        
    
    int array1[] = {1,2,2,1};
    printf("Test 1 = %d\r\n",isPalindrome(createLLWithValues(array1,sizeof(array1)/sizeof(array1[0]))));

    int array2[] = {1,2};
    printf("Test 2 = %d\r\n",isPalindrome(createLLWithValues(array2,sizeof(array2)/sizeof(array2[0]))));

    int array3[] = {1,1};
    printf("Test 3 = %d\r\n",isPalindrome(createLLWithValues(array3,sizeof(array3)/sizeof(array3[0]))));

    int array4[] = {1,0,1};
    printf("Test 4= %d\r\n",isPalindrome(createLLWithValues(array4,sizeof(array4)/sizeof(array4[0]))));
    return 0;
}


