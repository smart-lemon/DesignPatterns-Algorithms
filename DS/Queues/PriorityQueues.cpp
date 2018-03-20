#include "./../../Include/CommonInc.h"
#include "./T/PriorityQueues.h"


/* 
    Priority Queue : 
      -> Simple version (without Template programming)
*/


#include <iostream> 
using namespace std;


class Element {
    // Next element in the linked list
    public:
    Element *next;
    int     priority;
    int     data;

    Element(int iprio, int idata){
        priority = iprio;
        data     = idata;
        next     = NULL;
    }
};


class PriorityQueue {
    Element *queue;
    bool isEmpty();
    
public: 
    PriorityQueue();
    void insert(int p, int d);
    int getMaximum();
    int deleteMax();
    int deleteMin();
    void printQueue();

};

/* 
    The constructor 
*/
PriorityQueue :: PriorityQueue() {
    queue = NULL;
} 


/* 
    Helper to check if the queue is empty 
*/
bool PriorityQueue :: isEmpty(){
    return queue == NULL;
}


/* 
    Inserts an element in the Priority Queue with an incoming priority at an appropriate place 
*/
void PriorityQueue :: insert( int incomingPriority, 
                              int incomingData ){

    Element *newElement = new Element(incomingPriority, incomingData);
        
    if(isEmpty()){
        queue = newElement;
        return;
    }

    // Traverse the list and find a position to insert new node
    if(incomingPriority > queue->priority) { // If the incoming priority is greater than the head 
        newElement->next = queue;
        queue = newElement;

    } else {
        Element *temp = queue;
        while(temp && (temp->priority > incomingPriority)) {
                temp = temp->next;
        }

        newElement->next = temp->next;
        temp->next = newElement;
    }
}


/* 
   Peeks at the element with the highest priority 
*/
int PriorityQueue :: getMaximum(){
    if(isEmpty())
        return NULL;
    
    Element *front = queue;
    return front->data;
}


/* 
    Reads and deletes the element with the highest priority 
*/
int PriorityQueue :: deleteMax(){
    if(isEmpty())
        return NULL;

    Element *front = queue;
    queue = queue->next;

    int ret = front->data;
    delete front;

    // returns that data that was at the front
    return ret;
}


/* 
    Reads and deletes the element with the lowest priority 
*/
int PriorityQueue :: deleteMin()
{
    Element *temp = queue;
    Element *prev = NULL;

    while(temp && temp->next) {
        prev = temp;
        temp = temp->next;
    }

    int ret = temp->data;
    prev->next = NULL;

    delete temp;
    return ret;
}

/* 
    Prints the Priority Queue 
*/
void PriorityQueue :: printQueue(){
    if(isEmpty()){
        return;
    }

    Element *temp = queue;
    
    while(temp) {
        cout << "[P: " << temp->priority << " D: " << temp->data << "] -> "; 
        temp = temp->next;
    }
    cout << " NULL" << endl;
}


/* 
    Test function for Priority Queues
*/
void testPriorityQueues() 
{
   PriorityQueue *queue = new PriorityQueue();

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


void testPriorityQueuesT() 
{
   PriorityQueueT<int, int> *queue = new PriorityQueueT<int, int>();

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