#include "./../../Include/Common.h"

using namespace std;


static int partitionn(int *data, int low, int high) {

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
        int p_index = partitionn(data, low, high);

        quick_sort(data, low , p_index - 1);
        quick_sort(data, p_index + 1, high);
    }
}


int partition(int *data, int left, int right, int pivot) {
   int leftPointer = left;
   int rightPointer = right - 1;

   while(true) {

        cout << "P: " << pivot <<  "; ";  print1DArray(data, left, right);

        while(data[leftPointer] < pivot) {
            leftPointer++;
        }
        
        while(rightPointer > 0 && data[rightPointer] > pivot) {
            rightPointer--;
        }

        if(leftPointer < rightPointer) {
            swap(data, leftPointer, rightPointer);
        } else {
            break;
        }
   }
	
   swap(data, leftPointer, right);

   return leftPointer;
}

void quickSort(int *data, int left, int right) {

   if(right > left) {
      int pivot = data[right];
      int partitionPoint = partition(data, left, right, pivot);
      quickSort(data, left, partitionPoint - 1);
      quickSort(data, partitionPoint + 1, right);
   }        
}


void testQuickSort()
{
    int dataset[] = {-2, 0, 5, 4, -1, 8, -3, 2, 2, 6, -3,  4, 7, 1, 3, 9, -4};

    int low = 0, high = sizeof(dataset) / sizeof(dataset[0]);

    quick_sort(dataset, low, high - 1);

    cout << "Quick sort: ";
    print1DArray(dataset, high);
    
}

///  {-2, 0, 5, 4, -1, 8, -3, 2, 2, 6, -3,  4, 7, 1, 3, 9, -4};
///  {0, -2, -3, -1, -4, -2, -1};