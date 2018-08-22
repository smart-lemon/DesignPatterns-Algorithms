#include "./../../../Include/Common.h"


int* remove_dup(int A[], int sz)
{    /* 
        Instructions : Alocate the memory of Output array of maximum size n. 
        Fill the new array with unique elements, which have duplicates entries in input array 
        Size of Output array will be less than n. 
    */
    int *output = nullptr;

    if(sz == 1)
        return output;

    // Add your code below this line. Do not modify any other code.
    sort(A, A + sz);

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
    
    // Add your code above this line. Do not modify any other code.
    return output;
    
}