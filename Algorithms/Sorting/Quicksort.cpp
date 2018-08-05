#include "./../../Include/Common.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int left = low - 1, right = high + 1;
 
    while (true) {
 
        // Find leftmost element greater than
        // or equal to pivot
        do {
            left++;
        } while (arr[left] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            right--;
        } while (arr[right] > pivot);
 
        // If two pointers met.
        if (left >= right)
            return right;
 
        swap(arr, left, right);
    }
}
 
// Generates Random Pivot
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr, random, low);
 
    return partition(arr, low, high);
}
 
void quickSort(int *arr, int low, int high)
{
    if (low < high) {

        int pi = partition_r(arr, low, high);
 
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void testQuickSort()
{
    int dataset[] =  {-2, 0, 5, 4, -1, 8, -3, 2, 2, 6, -3,  4, 7, 1, 3, 9, -4};

    int low = 0, high = sizeof(dataset) / sizeof(dataset[0]);

    quickSort(dataset, low, high - 1);

    cout << "Quick sort: ";
    print1DArray(dataset, high);
    
}

///  {-2, 0, 5, 4, -1, 8, -3, 2, 2, 6, -3,  4, 7, 1, 3, 9, -4};
///  {0, -2, -3, -1, -4, -2, -1};