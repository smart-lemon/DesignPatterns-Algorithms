#include "./../../Include/CommonInc.h"

#include <iostream> 

using namespace std;

template <typename Priority, typename Data>
class Element {

    public:
    Element(Priority p, Data d){
        priority = p;
        data = d;
        next = NULL;
    }

    Priority priority;
    Data data;

    // Next element in the linked list
    Element<Priority, Data> *next;
};

template <typename Priority, typename Data>
class PriorityQueue {

    Element<Priority, Data> *queue;

    bool isEmpty(){
        return queue == NULL;
    }

    public: 
    PriorityQueue() {
        queue = NULL;
    }

    void insert(Priority incomingPriority, Data incomingData){

        Element<Priority, Data> *newElement = new Element<Priority, Data>(incomingPriority, incomingData);
         
        if(isEmpty()){
            queue = newElement;
            return;
        }

        // Traverse the list and find a position to insert new node
        if(incomingPriority > queue->priority) { // If the incoming priority is greater than the head 
            newElement->next = queue;
            queue = newElement;

        } else {
            Element<Priority, Data> *temp = queue;
            while(temp && (temp->priority > incomingPriority)) {
                 temp = temp->next;
            }

            newElement->next = temp->next;
            temp->next = newElement;
        }
    }

    Data getMaximum(){
        if(isEmpty())
            return NULL;
        
        Element<Priority, Data> *front = queue;
        return front->data;
    }

    Data deleteMax(){
        if(isEmpty())
            return NULL;

        Element<Priority, Data> *front = queue;
        queue = queue->next;

        Data ret = front->data;
        delete front;
        return ret;
    }

    Data deleteMin()
    {
        Element<Priority, Data> *temp = queue;
        Element<Priority, Data> *prev = NULL;

        while(temp && temp->next) {
            prev = temp;
            temp = temp->next;
        }

        Data ret = temp->data;
        prev->next = NULL;

        delete temp;
        return ret;
    }
};



void testPriorityQueues() 
{
   PriorityQueue<int, int> *queue = new PriorityQueue<int, int>();

   queue->insert(1, 100);
   queue->insert(2, 200);
   queue->insert(3, 300);
   queue->insert(4, 400);
   queue->insert(5, 500);

   int data = queue->deleteMax();

   cout << "Priority Queue: deleted:  " << data << endl;
}