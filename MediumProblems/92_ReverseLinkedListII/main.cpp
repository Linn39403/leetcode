#include <iostream>
#include <assert.h>
void myassert(bool bResult, bool bExpected, char * cPtrTestName);

using std::cout;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* CreateNode(int x)
{
    ListNode *head = new ListNode(x);
    if(head == NULL) return nullptr;
    return head;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int LLSize = 0;
        int diffCnt = right - left;
        int * arr = new int[500];
        while(head!=nullptr){
            arr[LLSize] = head->val;
            head = head->next;
            LLSize++;
        }        
        ListNode * ptr = nullptr, * ptrCpy = nullptr;
        if(left==1){
            ptr = CreateNode(arr[left+diffCnt-1]);
            diffCnt--;
        }else{
            ptr = CreateNode(arr[0]);
        }
        ptrCpy = ptr;
        for(int i=1; i<LLSize; i++){
            if(i >= left-1 && i < right){
                ptr->next = CreateNode(arr[left+diffCnt-1]);
                diffCnt--;
            }else{
                ptr->next = CreateNode(arr[i]);
            }
            ptr = ptr->next;
        }
        delete[] arr;
        return ptrCpy;
    }
};

int main(void)
{
    //create a LL
    ListNode * head = new ListNode(1);
#if 1 
    ListNode * ptr = head;
    for(int i=2; i<6;i++){
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
#endif 
    Solution *mySol = new Solution();
    ListNode * testPtr = mySol->reverseBetween(head, 2, 4);
    ListNode * testPtr2 = testPtr;
    while(testPtr != nullptr){
        cout << " " << testPtr->val ;
        testPtr = testPtr->next;
    }
    delete testPtr2;
    delete head;

    return 0;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName)
{
    if(bResult != bExpected)
    {
        printf("%s. ERROR\r\n",cPtrTestName);
    }
    else
    {
        printf("%s. OK\r\n",cPtrTestName);
    }
}

