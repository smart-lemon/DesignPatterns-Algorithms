#include "./../../Include/CommonInc.h"

using namespace std;

void merge(int *dataset, int *temp, int left, int mid, int right)
{
      
}

void mergesort(int *dataset, int *temp, int left, int right){

    if(right > left)
    {
        // calculate mid 
        int mid = (left + right)/2;

        // divide and conquer
        mergesort(dataset, temp, left, mid);
        mergesort(dataset, temp, mid + 1, right);

        merge(dataset, temp, left, mid, right);
    }
}


void testMergesort()
{
    int dataset[] = {102, 54, -19, 99, 0, 69};
    int low = 0, high = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Mergesort: ";
    print1DArray(dataset, high);
    
}