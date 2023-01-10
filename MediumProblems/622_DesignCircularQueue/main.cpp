#include <iostream>
#include <assert.h>

class MyCircularQueue {
private:
    int front;
    int rear;
    int * QUEUE;
    int SIZE;
public:
    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        SIZE = k;
        QUEUE = new int[SIZE];
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        if(front == -1 && rear == -1 ){
            front = 0; rear = 0;
        }
        else if(front != 0 && rear == SIZE - 1){
            rear = 0;
        }
        else{
            rear++;
        }
        QUEUE[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        if(front == rear){
            front = -1; rear = -1;
        }else{
            front = (front == (SIZE-1) ? 0 : ++front);
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()==true) return -1;
        return QUEUE[front];
    }
    
    int Rear() {
        if(isEmpty()==true) return -1;
        return QUEUE[rear];        
    }
    
    bool isEmpty() {
        if((front == -1) && (rear == -1)) return true;
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == SIZE -1 ) || (rear+1 == front)){ 
            return true;
        }
        return false;
    }
};

int main(void)
{
    MyCircularQueue* myCirQueue = new MyCircularQueue(4);
    std::cout << myCirQueue->enQueue(3) << std::endl; //return True
    std::cout << myCirQueue->Front()    << std::endl; //return 3
    std::cout << myCirQueue->isFull()   << std::endl; //return False
    std::cout << myCirQueue->enQueue(7) << std::endl; //return True
    std::cout << myCirQueue->enQueue(2) << std::endl; //return True
    std::cout << myCirQueue->enQueue(5) << std::endl; //return True
    std::cout << myCirQueue->deQueue()  << std::endl; //return True
    std::cout << myCirQueue->enQueue(4) << std::endl; //return True
    std::cout << myCirQueue->enQueue(2) << std::endl; //return False (must be false)
    std::cout << myCirQueue->isEmpty()  << std::endl; //return False (msut be false)
    std::cout << myCirQueue->Rear()     << std::endl; //return 4 ( must be 4)
    return 0;
}

