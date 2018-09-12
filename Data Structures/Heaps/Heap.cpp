#include "./../../Include/Common.h"

const int MIN_HEAP = 0;
const int MAX_HEAP = 1; 

class Heap {

    private: 
    int *array;
    int count;
    int capacity;
    int heapType;


    int compare(int data_a, int data_b){
        if(heapType == MIN_HEAP)
            return data_a < data_b;
        if(heapType == MAX_HEAP)
            return data_a > data_b;
    }


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

    // Resize the heap by doubling its capacity
    void resizeHeap(){
        int *newArray = new int[2 * capacity];

        for(int i = 0; i < capacity; i++){
            newArray[i] =  array[i];
        }

        delete [] array;
        array = newArray;

        capacity = 2 * capacity;
    }

    // Inserts new data into the Heap and percolates it up
    int insert(int data) {
        if(count == capacity){
            resizeHeap();
        }
        int i = count - 1;
        percolateUp(data, i);
    }

    int deleleMin() {

    }

    // In a min heap, the node is sent upward till its childern are larger
    // In a max heap, the node is sent upward till its childern are smaller 
    int percolateUp(int data, int i) {
        while(i >= 0 && compare(data, array[(i - 1)/2]))
        {
            array[i] = array[(i - 1)/2]; // trade places
            i = (i - 1)/2;
        }
        array[i] = data;
    }
    
    int bubbleDown(int i) {
        int l = leftChild(i);
        int r = rightChild(i);
        
    }
};

void testHeap() {

}