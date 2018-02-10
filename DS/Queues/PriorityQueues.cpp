#include "./../../Include/CommonInc.h"
#include "./../../Include/Helpers.h"


#include <iostream> 
using namespace std;

template <typename Priority, typename Data>
PriorityQueue <Priority, Data> :: PriorityQueue() {
    queue = NULL;
} 

template <typename Priority, typename Data>
bool PriorityQueue <Priority, Data> :: isEmpty(){
    return queue == NULL;
}

template <typename Priority, typename Data>
void PriorityQueue <Priority, Data> :: insert( Priority incomingPriority, 
                                               Data incomingData ){

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

template <typename Priority, typename Data>
Data PriorityQueue <Priority, Data> :: getMaximum(){
    if(isEmpty())
        return NULL;
    
    Element<Priority, Data> *front = queue;
    return front->data;
}

template <typename Priority, typename Data>
Data PriorityQueue <Priority, Data> :: deleteMax(){
    if(isEmpty())
        return NULL;

    Element<Priority, Data> *front = queue;
    queue = queue->next;

    Data ret = front->data;
    delete front;
    return ret;
}

template <typename Priority, typename Data>
Data PriorityQueue <Priority, Data> :: deleteMin()
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

template <typename Priority, typename Data>
void PriorityQueue <Priority, Data> :: printQueue(){
    if(isEmpty()){
        return;
    }

    Element<Priority, Data> *temp = queue;
    
    while(temp) {
        cout << "[P: " << temp->priority << " D: " << temp->data << "] -> "; 
        temp = temp->next;
    }
    cout << " NULL" << endl;
}


void testPriorityQueues() 
{
   PriorityQueue<int, int> *queue = new PriorityQueue<int, int>();

   queue->insert(1, 100);
   queue->printQueue();
   queue->insert(4, 400);
   queue->printQueue();
   queue->insert(2, 200);
   queue->printQueue();
   queue->insert(5, 500);
   queue->printQueue();
   queue->insert(3, 300);

   queue->printQueue();

   int data = queue->deleteMax();

   cout << "Priority Queue: deleted:  " << data << endl;
}