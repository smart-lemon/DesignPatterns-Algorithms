#include "./../../Include/Common.h"


static int partition(int *data, int low, int high) {

    // Random has to lie between low and high : low + rand % (Number of elements in arr[l..h])

    int left = low + 1,  right = high,  pivot = data[low];

    while (left < right) {

        cout << "P: " << pivot <<  " at " << low << "; ";  print1DArray(data, low, high);

        // Everthing on the left of pivot is lower than the pivot 
        while ((left <= right) && data[left] <= pivot) 
            left++;

        // Everything on the right of the pivot is greater than the pivot 
        while((left <= right) && data[right] > pivot)
            right--;

        if (left < right)
            swap(data, left, right);
    }

    cout << "Swap " << data[low] << " at " << low  << " with " << data[right] << " at " << right  << endl;
    
    swap(data, low, right);

    return right;
}

int partition_random(int *data, int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(nullptr));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(data, random, low);
 
    return partition(data, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition_random(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
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