#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

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
struct ListNode * createLL(int data)
{
    struct ListNode * head = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(head != NULL);
    head->val = data;
    head->next = NULL;
    return head;
}

struct ListNode * insertBegLL(struct ListNode * start,  int data)
{
    struct ListNode * newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(newNode != NULL);

    newNode->val = data;
    newNode->next = start;
    start = newNode;
    return start;
}

struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL) return NULL;
    struct ListNode  * RevHead = createLL(head->val); 
    if( head->next == NULL) return RevHead;
    head = head->next;
    do
    {
        RevHead = insertBegLL(RevHead, head->val);
        head = head->next;
    } while (head!=NULL);
    return RevHead;
}

int main(void)
{        
    struct ListNode * LL = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * LLHead = LL;
    LL->val = 1;
    for(int i=2;i<6;i++){
        LL->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        LL = LL->next;
        LL->val = i;
    }
    LL->next = NULL;
    LL = reverseList(LLHead);
    
    //print
    do{
        printf("%d\t", LL->val);
        LL = LL->next;
    }while(LL != NULL);
    return 0;
}


