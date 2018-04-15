#include "./../../Include/Common.h"
#include <stdlib.h> // for rand()

using namespace std;


static int partition(int *data, int low, int high) {

    // Random has to lie between low and high : low + rand % (Number of elements in arr[l..h])
    int random = low + rand() % (high - low + 1);

    int left = low,  right = high,  pivot = data[random];

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
    swap(data, random, right);
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

    quick_sort(dataset, low, high - 1);

    cout << "Quick sort: ";
    print1DArray(dataset, high);
    
}