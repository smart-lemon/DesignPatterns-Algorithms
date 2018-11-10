#include "./../../Include/Common.h"


// Not tested yet

class Stack {
    int *pile; 
    int top;
    const int MAX_SIZE = 100;
    
    public: 
    Stack(){
        pile = new int[MAX_SIZE];
        top = -1;
    }

    // Helpers to check if the stack is empty/full
    inline bool isEmpty(){
        return top < 0;
    }
    
    inline bool isFull(){
        return top + 1 == MAX_SIZE;
    }

    // Take off what's on the top of the stack
    int pop() {
        if(isEmpty())
            cout << "Stack is empty" << endl;
        
        int data = pile[top]; 
        top--;
        return data;
    }

    // Put data on the top of the stack
    void push(int data) {
        if(isFull())
            cout << "Stack is full" << endl;
        top++;
        pile[top] = data;
        return;
    }

    // Peek at what's on the top of the stack
    int peek() {
        if(top < 0)
            cout << "Nothing on the stack" << endl;
        return pile[top];
    }
};

int testStacks() {
    Stack stack;

    return 0;
}