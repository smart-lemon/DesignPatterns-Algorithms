#include "./../../Include/Common.h"

using namespace std;

static int n;


static int partition(int *data, int low, int high) {

    int left = low,  right = high,  pivot = data[low];

    while (left < right) {

        // Everthing on the left of pivot is lower than the pivot 
        while ((left <= right) && data[left] <= pivot) // <= is because left is the pivot initially
            left++;

        // Everything on the right of the pivot is greater than the pivot 
        while((left <= right) && data[right] > pivot)
            right--;

        if (left < right)
            swap(data, left, right);

       //  cout << "P: " << pivot << "; ";  print1DArray(data, low, high);
    }

    // Put the pivot in the 'rigthful' place
    swap(data, low, right);
    //  cout << "swap " << data[low] << "&" << data[right] << endl;

    return right;
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
    int dataset[] = {0, 5, 4, -1, 8, 2, 6, 4, 7, 1, 3, 9, -4};

    int low = 0, high = sizeof(dataset) / sizeof(dataset[0]);
    n = high;

    quick_sort(dataset, low, high - 1);

    cout << "Quicksort: ";
    print1DArray(dataset, high);
    
}