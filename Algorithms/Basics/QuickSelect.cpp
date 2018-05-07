#include "./../../Include/Common.h"
#include <climits>
using namespace std;

/*
    Finds the k-th largest element in an unsorted array (Randomized Quick Select)
    Runtime: O(n) on average. O(n²) in the worst case. 
*/

// State : untested 
static int partition(int *data, int low, int high) {

    // Random has to lie between low and high : low + rand % (Number of elements in arr[l..h])
    int random = low + rand() % (high - low + 1);

    int left = low,  right = high,  pivot = data[random];

    while (left < right) {

        // Everthing on the left of pivot is lower than the pivot (as you are finding the smallest)
        while ((left <= right) && data[left] <= pivot)
            left++;

        if (left < right)
            swap(data, left, right);

    }

    // Put the pivot in the 'rigthful' place
    swap(data, random, right);

    cout << "P: " << pivot << " "; print1DArray(data, low, high);  

    return right;
}


int quick_select(int *data, int low, int high, int k){
    int split = 0;
    
    if(k >= 0 && k < (high - low + 1))
    {
        split = partition(data, low, high);

        // How far is k from split - depending on this choose the search pool

        // Lucky, found the pivot
        if((split - k) == (k - low))
            return data[split]; 
        else if((split - k) > (k - low))
            return quick_select(data, low, split - 1, k) ;

        return quick_select(data, split + 1, high, k);
    }
    return INT_MAX;
}

void testQuickSelect(){
    int kth_smallest = 5;
    int dataset[] = {0, 5, 4, -1, 8, 2, 6, 4, 7, 1, 3, 9, -4};

    int low = 0, high = sizeof(dataset) / sizeof(dataset[0]);

    int ret = quick_select(dataset, low, high - 1, kth_smallest);

    cout << kth_smallest << " Kth smallest is " << ret << endl;
}