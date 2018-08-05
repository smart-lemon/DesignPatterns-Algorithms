// namespace std have been included for this problem.
#include <stdlib.h>     /* srand, rand */
#include <time.h>

void swap(int *numbers, int a, int b){
    int temp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int left = low - 1, right = high + 1;
 
    while (true) {
         do {
            left++;
        } while (arr[left] < pivot);
 
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
// Add any helper functions(if needed) above.
int* remove_dup(int A[], int sz)
{    /* Alocate the memory of Output array of maximum size n. 
    Fill the new array with unique elements, which have duplicates entries in input array 
    Size of Output array will be less than n. */
    int *output = nullptr;
    // Add your code below this line. Do not modify any other code.
    quickSort(A, 0, sz - 1);
    
    int k = 0; 
    output = new int[sz];
    bool flag = false;
    for(int i = 1; i < sz; i++){
        while(A[i] == A[i-1]){
            i++;
            flag = true;
        }
        if(flag)
        {
            output[k] = A[i - 1];
            k++;
            flag = false;
        }
    }
    
    
    for(int i = 0; i < k; i++){
        cout << output[i] << " "; 
    }
    cout << "===" << endl;
    // Add your code above this line. Do not modify any other code.
    return output;
    
}