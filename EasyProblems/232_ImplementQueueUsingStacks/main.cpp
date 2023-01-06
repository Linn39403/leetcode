#include <iostream>

/*
    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

    Constraints:

    1 <= x <= 9
    At most 100 calls will be made to push, pop, peek, and empty.
    All the calls to pop and peek are valid.
*/

class MyQueue {
    private:
        const int SIZE = 100;
        int front, rear;
        int * ptr;
public:
    MyQueue() {
        front = -1;
        rear = -1;
        ptr = new int[100];
    }
    
    ~MyQueue(){
        delete[] ptr;
    }

    void push(int x) {
        if(rear == SIZE - 1)
        {
            return;
        }
        else if( front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear ++;
        }
        ptr[rear] = x;
    }
    
    int pop() {
        int val = this->peek();
        front++;
        if(front>rear)
        {
            front = -1;
            rear = -1;
        }
        return val;
    }
    
    int peek() {
        if(front == -1 || front > rear)
        {
            return -1;
        }
        else
        {
            return ptr[front];
        }  
    }
    
    bool empty() {
        if( front == -1 && rear == -1 ) return true;
        return false;
    }
};

int main(void)
{
    MyQueue* obj = new MyQueue();
    obj->push(10);
    obj->push(20);
    std::cout << "Peek " << obj->peek() << std::endl;
    std::cout << "Pop " << obj->pop() << std::endl;
    std::cout << "Empty " << obj->empty() << std::endl;
    return 0;
}