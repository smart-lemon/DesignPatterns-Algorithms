#include "./../../Include/Common.h"
using namespace std;

class Element {
    // Next element in the linked list
    public:
        int data;
        Element *next;
        
        Element(int in) : data(in), next(nullptr) { }
};

class Queue {

    Element *queue; 

    Queue() {
        queue = nullptr;
    }

    bool isEmpty(){
        return queue == NULL;
    }

    Element *createNewElement(int data) {
         return new Element(data);
    }

    void insert(int data) {
        if(queue == nullptr){
            queue = createNewElement(data);
            return;
        }


    }
     
    int retrive(){

    }
     
}; 