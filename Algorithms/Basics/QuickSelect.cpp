#include "./../../Include/Common.h"

using namespace std;

/*
    Finds the k-th largest element in an unsorted array (Randomized Quick Select)
    Runtime: O(n) on average. O(n²) in the worst case. 
*/


static int partition(int *data, int low, int high) {

    // Random has to lie between low and high : low + rand % (Number of elements in arr[l..h])
    int random = low + rand() % (high - low + 1);

    int left = low,  right = high,  pivot = data[random];

    while (left < right) {

        // Everthing on the left of pivot is lower than the pivot (as you are finding the smallest)
        while ((left <= right) && data[left] <= pivot) // <= is because left is the pivot initially
            left++;

        if (left < right)
            swap(data, left, right);

    }

    // Put the pivot in the 'rigthful' place
    swap(data, random, right);

    return right;
}


int quick_select(int *data, int low, int high, int k){
    int split = 0;
    while(low < high){
        split = partition(data, low, high);

        // Lucky, found the pivot
        if(split - k == k - low)
            return data[split];
        
        else if((split - k) > (k - low))
            return quick_select(data, split, high, k);
        
    }
}

void testQuickSelect(){

}