#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLL(ListNode * head)
{
    ListNode * headCpy = head;
    std::cout << std::endl;
    while(headCpy != nullptr){
        std::cout << headCpy->val << " ";
        headCpy = headCpy->next;
    }    
}

class Solution {
public:
    int getLen(ListNode * head){
        int len = 0;
        ListNode * headCpy = head;
        while(headCpy->next != nullptr){
            len++;
            headCpy = headCpy->next;
        }
        return (++len);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        if(head == nullptr || head->next == nullptr) return head;

        int len = getLen(head);
        int loopCnt = k;
        if(k > len){
            loopCnt = (k%len);
            if(loopCnt ==0 ) return head;
        }
        do{
            ListNode * headCpy = head;
            ListNode * B4LastNode;
            while(headCpy->next != nullptr){
                B4LastNode = headCpy;
                headCpy = headCpy->next; //go to the end of LL
            }
            B4LastNode->next = nullptr;
            headCpy->next = head;
            head = headCpy;
        }while(--loopCnt>0);
         return head;       
    }
};

int main(void)
{
    ListNode * head = new ListNode(1);
    ListNode * headCpy = head;
    for(int i = 2; i <6; i++){
        headCpy->next = new ListNode(i);
        headCpy = headCpy->next;
    }
    headCpy->next = nullptr;


    Solution mySol;
    std::cout << "Original LL is " << std::endl;
    printLL(head);
    std::cout << std::endl;
    std::cout << "After rotated 20 times" << std::endl; 
    head = mySol.rotateRight(head, 2);
    printLL(head);
    delete head;

    return 0;
}