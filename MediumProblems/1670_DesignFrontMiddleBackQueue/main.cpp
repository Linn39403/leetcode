#include <iostream>

/**
 * Design a queue that supports push and pop operations in the front, middle, and back.
 * Implement the FrontMiddleBack class:
 * FrontMiddleBack() Initializes the queue.
 * void pushFront(int val) Adds val to the front of the queue.
 * void pushMiddle(int val) Adds val to the middle of the queue.
 * void pushBack(int val) Adds val to the back of the queue.
 * int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
 * int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
 * int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
 * Notice that when there are two middle position choices, the operation is performed on the frontmost middle position choice. For example:
 * Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
 * Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
 */
struct Node {
    int val;
    Node* next;
    Node* prev;
};

class FrontMiddleBackQueue {
private:
    Node* head;
    Node* tail;
    int size;

public:
    FrontMiddleBackQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void pushFront(int val) {
        Node* temp = new Node();
        temp->val = val;
        temp->next = head;
        temp->prev = nullptr;
        if (head != nullptr) {
            head->prev = temp;
        }
        head = temp;
        if (tail == nullptr) {
            tail = head;
        }
        size++;
    }

    void pushMiddle(int val) {
        Node* temp = new Node();
        temp->val = val;
        if (head == nullptr) {
            head = tail = temp;
            temp->next = temp->prev = nullptr;
        } else {
            int mid = size / 2;
            Node* curr = head;
            for (int i = 0; i < mid; i++) {
                curr = curr->next;
            }
            temp->next = curr;
            temp->prev = curr->prev;
            if (curr->prev != nullptr) {
                curr->prev->next = temp;
            } else {
                head = temp;
            }
            curr->prev = temp;
        }
        size++;
    }

    void pushBack(int val) {
        Node* temp = new Node();
        temp->val = val;
        temp->next = nullptr;
        temp->prev = tail;
        if (tail != nullptr) {
            tail->next = temp;
        }
        tail = temp;
        if (head == nullptr) {
            head = tail;
        }
        size++;
    }

    int popFront() {
        if (head == nullptr) {
            return -1;
        }
        int val = head->val;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
        return val;
    }

    int popMiddle() {
        if (head == nullptr) {
            return -1;
        }
        int mid = (size - 1) / 2;
        Node* curr = head;
        for (int i = 0; i < mid; i++) {
            curr = curr->next;
        }
        int val = curr->val;
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
        }
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev;
        }
        delete curr;
        size--;
        return val;
    }

    int popBack() {
        if (tail == nullptr) {
            return -1;
        }
        int val = tail->val;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
        return val;
    }
};

int main(void)
{        
#if 1
    FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
    obj->pushFront(1);
    obj->pushBack(2);
    obj->pushMiddle(3);
    obj->pushMiddle(4);
    std::cout << "Pop Front : " << obj->popFront() << std::endl;
    std::cout << "Pop Middle : " << obj->popMiddle() << std::endl;
    std::cout << "Pop Middle : " << obj->popMiddle() << std::endl;
    std::cout << "Pop Back : " << obj->popBack() << std::endl;
    std::cout << "Pop Front : " << obj->popFront() << std::endl;
#endif
#if 1
    FrontMiddleBackQueue* obj1 = new FrontMiddleBackQueue();
    obj1->pushMiddle(1);
    obj1->pushMiddle(2);
    obj1->pushMiddle(3);
    std::cout << "Pop Middle : " << obj1->popMiddle() << std::endl;
    std::cout << "Pop Middle : " << obj1->popMiddle() << std::endl;
    std::cout << "Pop Middle : " << obj1->popMiddle() << std::endl;
#endif
    return 0;
}


