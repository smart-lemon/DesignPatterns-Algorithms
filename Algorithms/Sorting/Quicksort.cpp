#include "./../../Include/Common.h"

using namespace std;

static int n;

// Changed some thing and it is broken - TBD
static int partition(int *data, int low, int high) {

    int left = low + 1,  right = high,  pivot = data[low];

    while (left < right) {

        // Everthing on the left of pivot is lower than the pivot 
        while ((left < right) && data[left] <= pivot) // <= is because left is the pivot initially
            left++;

        // Everything on the right of the pivot is greater than the pivot 
        while ((right > left) && data[right] > pivot)
            right--;

        if (left < right)
            swap(data, left, right);

        cout << "P:" << pivot << " "; print1DArray(data, low + 1, high);  
    }

    cout << "Full : "; print1DArray(data, n);

    // Put the pivot in the 'rigthful' place between the left half and right half of the array
    if(low != right - 1 )
        swap(data, low, right - 1);

    return right - 1;
}

// Quicksort 
static void quick_sort(int *data, int low, int high)
{
    if (high > low) {
        int p_index = partition(data, low, high);

        quick_sort(data, low , p_index - 1);
        quick_sort(data, p_index + 1, high);
    }
}

void testQuickSort()
{
    int dataset[] = {0, 5, 4, -1, 8, 2, 6, 4, 3, 1, 7, 9, 1};

    int low = 0, high = sizeof(dataset) / sizeof(dataset[0]);
    n = high;

    quick_sort(dataset, low, high - 1);

    cout << "Quicksort: ";
    print1DArray(dataset, high);
    
}