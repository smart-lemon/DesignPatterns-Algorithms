#include "./../../Include/CommonInc.h"

using namespace std;


static void swap(int *numbers, int pos1, int pos2){

    int temp = numbers[pos1];
    numbers[pos1] = numbers[pos2];
    numbers[pos2] = temp;
}


static int partition(int *numbers, int low, int high) {

    int left,  right,  pivot = numbers[low];
    left = low; right = high; 

    while (left < right) {

        // everthing on the left of pivot is lower than the pivot 
        while (numbers[left] <= pivot) // <= is because left is the pivot initially
        {
            left++;
        }

        // everything on the right of the pivot is greater than the pivot 
        while (numbers[right] > pivot)
        {
            right--;
        }

        if (left < right)
            swap(numbers, left, right);
    }

    // put the pivot in the 'rigthful' place
    swap(numbers, low, right);

    return right;
}

// quicksort 
static void q_sort(int *numbers, int low, int high)
{
    if (high > low) {
        int p_index = partition(numbers, low, high);

        q_sort(numbers, low , p_index - 1);
        q_sort(numbers, p_index + 1, high);
    }
}

void testQuicksort()
{
    int dataset[] = {91, 62, -1, 89, 0, 45};
    int low = 0, high = sizeof(dataset)  / sizeof(dataset[0]);
    q_sort(dataset, low, high - 1);

    print1DArray(dataset, high);
    
}