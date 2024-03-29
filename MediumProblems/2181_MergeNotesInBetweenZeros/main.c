#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
    For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
    Return the head of the modified linked list.

    Constraints:
    * The number of nodes in the list is in the range [3, 2 * 105].
    * 0 <= Node.val <= 1000
    * There are no two consecutive nodes with Node.val == 0.
    * The beginning and end of the linked list have Node.val == 0.
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

struct ListNode* mergeNodes(struct ListNode* head) 
{
    //int head_arr[200000] = {0};
    int head_arr[10   ] = {0};
    int head_arr_len = 0;
    int ans_arr[10] = {0};
    int ans_arr_idx = 0;
    int sum = 0;
    do
    {
        head_arr[head_arr_len++] = head->val;
        head = head->next;
    } while ( head != NULL );
    
    for(int i=0; i<head_arr_len; i++)
    {
        if(head_arr[i] == 0)
        {
            if(sum)
            {
                ans_arr[ans_arr_idx++] = sum;
                sum = 0;
            }
        }
        else
        {
            sum += head_arr[i];
        }
    }
    return ( createLLWithValues(ans_arr, ans_arr_idx));
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

    int arr1[] = {0,3,1,0,4,5,2,0};
    struct ListNode * L1 = createLLWithValues(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printLL(mergeNodes(L1));

    int arr2[] = {7,9,6,6,7,8,3,0,9,5};
    //struct ListNode * L2 = createLLWithValues(arr2,sizeof(arr2)/sizeof(arr2[0]));
    //printLL(swapNodes(L2,5));
#if 0    
    int arr3[] = {1,2};
    struct ListNode * L3 = createLLWithValues(arr3,sizeof(arr3)/sizeof(arr3[0]));
    printLL(removeNthFromEnd(L3,1));

    int arr4[] = {1,2};
    struct ListNode * L4 = createLLWithValues(arr4,sizeof(arr4)/sizeof(arr4[0]));
    printLL(removeNthFromEnd(L4,2));

    int arr5[] = {1,2,3};
    struct ListNode * L5 = createLLWithValues(arr5,sizeof(arr5)/sizeof(arr5[0]));
    printLL(removeNthFromEnd(L5,3));
#endif
    return 0;
}


