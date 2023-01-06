#include <iostream>

/*
    Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

    Implement the MyStack class:

    void push(int x) Pushes element x to the top of the stack.
    int pop() Removes the element on the top of the stack and returns it.
    int top() Returns the element on the top of the stack.
    boolean empty() Returns true if the stack is empty, false otherwise.

    Constraints:

    1 <= x <= 9
    At most 100 calls will be made to push, pop, top, and empty.
    All the calls to pop and top are valid.

*/

class MyStack {
    private:
        const int SIZE = 100;
        int Idx;
        int * ptr;
public:
    MyStack() {
        Idx = -1;
        ptr = new int[100];
    }
    
    ~MyStack(){
        delete[] ptr;
    }

    void push(int x) {
        if(Idx < SIZE ){
            Idx++;
            ptr[Idx] = x;
        }
    }
    
    int pop() {
        int val = ptr[Idx];
        Idx--;
        return val;
    }
    
    int top() {
        return ptr[Idx];
    }
    
    bool empty() {
        if( Idx == -1 ) return true;
        return false;
    }
};

int main(void)
{
    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(20);
    std::cout << "Top " << obj->top() << std::endl;
    std::cout << "Pop " << obj->pop() << std::endl;
    std::cout << "Empty " << obj->empty() << std::endl;
    return 0;
}