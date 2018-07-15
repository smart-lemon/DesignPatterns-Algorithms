#include "./../../Include/Common.h"

using namespace std;


static int partition(int *data, int low, int high) {

    // Random has to lie between low and high : low + rand % (Number of elements in arr[l..h])
    int random = low + rand() % (high - low + 1);

    int left = low,  right = high,  pivot = data[random];

    while (left < right) {

        cout << "P: " << pivot <<  " at " << random << "; ";  print1DArray(data, low, high);

        // Everthing on the left of pivot is lower than the pivot 
        while ((left <= right) && data[left] <= pivot) 
            left++;

        // Everything on the right of the pivot is greater than the pivot 
        while((left <= right) && data[right] > pivot)
            right--;

        if (left < right)
            swap(data, left, right);

    }

    cout << "Swap " << data[random] << " at " << random  << " with " << data[right] << " at " << right  << endl;
    
    // Put the pivot in the 'rigthful' place
    swap(data, random, right);

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
    int dataset[] = {0, -2, -3, -1, -4, -2, -1};

    int low = 0, high = sizeof(dataset) / sizeof(dataset[0]);

    quick_sort(dataset, low, high - 1);

    cout << "Quick sort: ";
    print1DArray(dataset, high);
    
}

///  {-2, 0, 5, 4, -1, 8, -3, 2, 2, 6, -3,  4, 7, 1, 3, 9, -4};