#include "./../../../../Include/Common.h"


class MyCircularQueue {
    vector<int> queue;
    int front, rear;
    int k;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        queue.resize(k);
        front = rear = -1; 
        this->k = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isEmpty()){
            front = rear = 0;
        } else {
            if(isFull())
                return false;
            rear = (rear + 1) % k;
        }
        queue[rear] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        int value;
        if(isEmpty()){
            return false;
        } else {            
            value = queue[front];
            front = (front + 1) % k;
            if(front == rear){
                front = rear = -1; 
            }
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        return queue[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
         if(isEmpty())
            return -1;

        return queue[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(front == -1 && rear == -1)
            return true;
        
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(!isEmpty() && ((rear + 1) % k) == front)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */