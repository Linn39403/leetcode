#include <iostream>
#include <assert.h>
/*
    Design your implementation of the circular double-ended queue (deque).

    Implement the MyCircularDeque class:

    MyCircularDeque(int k) Initializes the deque with a maximum size of k.
    boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
    int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
    int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
    boolean isEmpty() Returns true if the deque is empty, or false otherwise.
    boolean isFull() Returns true if the deque is full, or false otherwise.
*/
class MyCircularDeque {
private:
    int front, rear, SIZE;
    int * DEQUE;
public:
    MyCircularDeque(int k) {
        front = -1; rear = -1;
        SIZE = k;
        DEQUE = new int[SIZE];
    }
    ~MyCircularDeque(){
        delete[] DEQUE;
    }
    bool insertFront(int value) {
        if(isFull()) return false;
        if( front == -1 ){
            front = 0; rear = 0;
        }else{
            if(front == 0){
                front = SIZE - 1;
            }else{
                front--;
            }
        }
        DEQUE[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(front == -1){
            front = 0; rear = 0;
        }else{
            if(rear == SIZE - 1){
                rear = 0;
            }else{
                rear++;
            }
        }
        DEQUE[rear] = value;        
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        //Deque left only one element
        if(front == rear){
            front = -1; rear = -1;
        }else if(front == SIZE - 1){
            front = 0;
        }else{
            front++;
        }   
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        //Deque left only one element
        if(front == rear){
            front = -1; rear = -1;
        }else if(rear == 0){
            rear = SIZE -1;
        }else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return DEQUE[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return DEQUE[rear];
    }
    
    bool isEmpty() {
        if((front == -1) && (rear == -1)) return true;
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == SIZE - 1) || (front == rear + 1)) return true;
        return false;
    }
};

int main(void)
{
    MyCircularDeque * mycirculardeque = new MyCircularDeque(8);
    std::cout << mycirculardeque->insertFront(5) << std::endl;  //return true
    std::cout << mycirculardeque->getFront()     << std::endl;  //return 5

#if 0
    std::cout << mycirculardeque->insertLast(1)  << std::endl;  //return true
    std::cout << mycirculardeque->insertLast(2)  << std::endl;  //return true
    std::cout << mycirculardeque->insertFront(3) << std::endl;  //return true
    std::cout << mycirculardeque->insertFront(4) << std::endl;  //return false
    std::cout << mycirculardeque->getRear()      << std::endl;  //return 2
    std::cout << mycirculardeque->isFull()       << std::endl;  //return True
    std::cout << mycirculardeque->deleteLast()   << std::endl;  //return True
    std::cout << mycirculardeque->insertFront(4) << std::endl;  //return True
    std::cout << mycirculardeque->getFront()     << std::endl;  //return 4
#endif
    

    return 0;
}

