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
   
    cout << endl << "{l: ";
    for(int i = l_start; i <= l_end; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << " --- " ;
    for(int i = r_start; i <= r_end; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << ":r} " << endl;
   

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


    cout << "{tl: ";
    for(int i = l; i <= l_end; i++)
    {
        cout << temp[i] << " ";
    }
    cout << " --- " ;
    for(int i = r; i <= r_end; i++)
    {
        cout << temp[i] << " ";
    }
    cout << ":rt} " << endl;
   

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
    int dataset[] = {102, 54, -19, 99, 0, 69, 23, 38};
    int low = 0, high = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Mergesort: ";
    print1DArray(dataset, high);

    int *output = new int[high];
    
    mergesort(dataset, output, 0, high - 1);
    cout << "Output : ";

    print1DArray(output, high);
}