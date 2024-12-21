#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

/**
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    struct ListNode * mList = NULL;
    struct ListNode * mListHead = NULL; 
    if(list1->val < list2->val)
    {
        mListHead = list1;
        list1 = list1->next;
    }else{
        mListHead = list2;
        list2 = list2->next;
    }
    mList = mListHead;
    
    while(list1 && list2)
    {
        if(list1->val < list2->val){
            mList->next = list1;
            list1 = list1->next;
        }else{
            mList->next = list2;
            list2 = list2->next;
        }
        mList = mList->next;
    }
    if(list1){
        mList->next = list1;
    }else{
        mList->next = list2;
    }
    return mListHead;
}

int main(void)
{        
    
    int array1_a[] = {1,2,4};
    int array1_b[] = {1,3,4};
    struct ListNode * LL1_a = createLLWithValues(array1_a,sizeof(array1_a)/sizeof(array1_a[0]));
    struct ListNode * LL1_b = createLLWithValues(array1_b,sizeof(array1_b)/sizeof(array1_b[0]));
    printLL(mergeTwoLists(LL1_a, LL1_b));
#if 0
    int array2[] = {1,1,2,3,3};
    struct ListNode * LL2 = createLLWithValues(array2,sizeof(array2)/sizeof(array2[0]));
    printLL(deleteDuplicates(LL2)); 

    int array3[] = {1,2};
    struct ListNode * LL3 = createLLWithValues(array3,sizeof(array3)/sizeof(array3[0]));
    printLL(deleteDuplicates(LL3));

    int array4[]= {1,1};
    struct ListNode * LL4 = createLLWithValues(array4,sizeof(array4)/sizeof(array4[0]));
    printLL(deleteDuplicates(LL4));
#endif
    return 0;
}


