

// ################ HELPER FUNCTIONS ################ //


// Stacks



//////// Priority Queue
template <typename Priority, typename Data>
class Element {
    Priority priority;
    Data data;

    // Next element in the linked list
    Element<Priority, Data> *next;
    public:
    Element(Priority p, Data d){
        priority = p;
        data = d;
        next = NULL;
    }
};

template <typename Priority, typename Data>
class PriorityQueueT {
    Element<Priority, Data> *queue;
    bool isEmpty();
    
public: 
    PriorityQueueT();
    void insert(Priority p, Data d);
    Data getMaximum();
    Data deleteMax();
    Data deleteMin();
    void printQueue();

};