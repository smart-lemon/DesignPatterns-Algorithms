

// ################ HELPER FUNCTIONS ################ //


// Stacks



//////// Priority Queue
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
    bool isEmpty();

    public: 
    PriorityQueue();
    void insert(Priority incomingPriority, Data incomingData);
    Data getMaximum();
    Data deleteMax();
    Data deleteMin();
    void printQueue();
    
};