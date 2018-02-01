#include "./../../Include/CommonInc.h"

using namespace std;

// First subarray is arr[l..m]
// Second subarray is arr[m + 1..r]
void merge(int *numbers, int *temp, int left, int mid, int right)
{
    int l_start = left; int l = left;
    int l_end = mid; 
    int r_start = mid + 1; int r = right;
    int r_end = right;

    int cnt = l_start;
  
    while((l_start <= l_end) && (r_start <= r_end))
    {
        if(numbers[l_start] < numbers[r_start])
        {
            temp[cnt] = numbers[l_start];
            l_start++;

        } else {
            temp[cnt] = numbers[r_start];
            r_start++;
        }
        cnt++;
    }

    // copy the left overs
    while (l_start <= l_end)
    {
        temp[cnt] = numbers[l_start];
        l_start++;
        cnt++;
    }

    while (r_start <= r_end)
    {
        temp[cnt] = numbers[r_start];
        r_start++;
        cnt++;
    }
  
    // merging of sub array done, now put back the sub array in the original data set
    for(int k = left; k <= right; k++) 
    {  
        numbers[k] = temp[k];
    }

}

void mergesort(int *numbers, int *temp, int left, int right){

    if(right > left)
    {
        // calculate mid 
        int mid = (left + right)/2;

        // divide and conquer
        mergesort(numbers, temp, left, mid);
        mergesort(numbers, temp, mid + 1, right);

        merge(numbers, temp, left, mid, right);
    }
}

void testMergesort()
{
    int dataset[] = {4, 2, 8, 0, 6, 7, 1, 3, 5, 9};
    int low = 0, high = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Mergesort of : ";
    print1DArray(dataset, high);

    int *output = new int[high];
    
    mergesort(dataset, output, 0, high - 1);
    cout << "Output : ";

    print1DArray(output, high);
}