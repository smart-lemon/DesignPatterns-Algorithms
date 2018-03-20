#include "./../../Include/Common.h"

using namespace std;

// 
static int partition(int *data, int low, int high) {

    int left,  right,  pivot = data[low];
    left = low; right = high; 

    while (left < right) {

        // everthing on the left of pivot is lower than the pivot 
        while (data[left] <= pivot) // <= is because left is the pivot initially
        {
            left++;
        }

        // everything on the right of the pivot is greater than the pivot 
        while (data[right] > pivot)
        {
            right--;
        }

        if (left < right)
            swap(data, left, right);
    }

    // put the pivot in the 'rigthful' place
    swap(data, low, right);

    return right;
}

// quicksort 
static void q_sort(int *data, int low, int high)
{
    if (high > low) {
        int p_index = partition(data, low, high);

        q_sort(data, low , p_index - 1);
        q_sort(data, p_index + 1, high);
    }
}

void testQuickSort()
{
    int dataset[] = {91, 62, -1, 89, 0, 45};
    int low = 0, high = sizeof(dataset)  / sizeof(dataset[0]);

    q_sort(dataset, low, high - 1);

    cout << "Quicksort: ";
    print1DArray(dataset, high);
    
}