#include "./../../Include/Common.h"

const int MIN_HEAP = 0;
const int MAX_HEAP = 1; 

class Heap {

    private: 
    int *array;
    int count;
    int capacity;
    int heapType;

    // Left child is at 2i + 1
    inline int leftChild(int i) {
        int left = 2 * i + 1;
        if(left >= count)
            return -1;
        return left;
    }

    // Right child is at 2i + 2
    inline int rightChild(int i){
        int right = 2 * i + 2;
        if(right >= count)
            return -1;
        return right;
    }
    public: 

    // Constructor for Heap, takes in initial capacity
    Heap(int iCapacity) : heapType(MIN_HEAP), capacity(iCapacity) 
    {
        array = new int[capacity];
        int count = 0;
    }


    int insert(int data) {

    }

    int deleleMin() {

    }

    int percolateUp(int i) {

    }
    
    int bubbleDown(int i) {

    }
}

void testHeap() {

}