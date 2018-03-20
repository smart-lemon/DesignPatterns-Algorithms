
#include <iostream> 
using namespace std;


//////// Priority Queue
template <typename Priority, typename Data>
class ElementT {

    public:
    Priority priority;
    Data data;

    // Next ElementT in the linked list
    ElementT<Priority, Data> *next;
    
    ElementT(Priority p, Data d){
        priority = p;
        data = d;
        next = NULL;
    }
};

template <typename Priority, typename Data>
class PriorityQueueT {
    ElementT<Priority, Data> *queue;
    bool isEmpty();
    
public: 
    PriorityQueueT();
    void insert(Priority p, Data d);
    Data getMaximum();
    Data deleteMax();
    Data deleteMin();
    void printQueue();

};

/* 
    The constructor 
*/
template <typename Priority, typename Data>
PriorityQueueT <Priority, Data> :: PriorityQueueT() {
    queue = NULL;
} 


/* 
    Helper to check if the queue is empty 
*/
template <typename Priority, typename Data>
bool PriorityQueueT <Priority, Data> :: isEmpty(){
    return queue == NULL;
}


/* 
    Inserts an ElementT in the Priority Queue with an incoming priority at an appropriate place 
*/
template <typename Priority, typename Data>
void PriorityQueueT <Priority, Data> :: insert( Priority incomingPriority, 
                                               Data incomingData ){

    ElementT<Priority, Data> *newElement = new ElementT<Priority, Data>(incomingPriority, incomingData);
        
    if(isEmpty()){
        queue = newElement;
        return;
    }

    // Traverse the list and find a position to insert new node
    if(incomingPriority > queue->priority) { // If the incoming priority is greater than the head 
        newElement->next = queue;
        queue = newElement;

    } else {
        ElementT<Priority, Data> *temp = queue;
        while(temp && (temp->priority > incomingPriority)) {
                temp = temp->next;
        }

        newElement->next = temp->next;
        temp->next = newElement;
    }
}


/* 
   Peeks at the Element with the highest priority 
*/
template <typename Priority, typename Data>
Data PriorityQueueT <Priority, Data> :: getMaximum(){
    if(isEmpty())
        return NULL;
    
    ElementT<Priority, Data> *front = queue;
    return front->data;
}


/* 
    Reads and deletes the Element with the highest priority 
*/
template <typename Priority, typename Data>
Data PriorityQueueT <Priority, Data> :: deleteMax(){
    if(isEmpty())
        return NULL;

    ElementT<Priority, Data> *front = queue;
    queue = queue->next;

    Data ret = front->data;
    delete front;
    return ret;
}


/* 
    Reads and deletes the Element with the lowest priority 
*/
template <typename Priority, typename Data>
Data PriorityQueueT <Priority, Data> :: deleteMin()
{
    ElementT<Priority, Data> *temp = queue;
    ElementT<Priority, Data> *prev = NULL;

    while(temp && temp->next) {
        prev = temp;
        temp = temp->next;
    }

    Data ret = temp->data;
    prev->next = NULL;

    delete temp;
    return ret;
}

/* 
    Prints the Priority Queue 
*/
template <typename Priority, typename Data>
void PriorityQueueT <Priority, Data> :: printQueue(){
    if(isEmpty()){
        return;
    }

    ElementT<Priority, Data> *temp = queue;
    
    while(temp) {
        cout << "[P: " << temp->priority << " D: " << temp->data << "] -> "; 
        temp = temp->next;
    }
    cout << " NULL" << endl;
}

