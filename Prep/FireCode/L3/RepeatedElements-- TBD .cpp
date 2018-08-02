// namespace std have been included for this problem.
void swap(int *numbers, int a, int b){
    int temp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = temp;
}


void bubble_sort(int *data, int n){

   bool swapped = true;

   // No more passes required if swapped remains false
   for(int pass = n - 1; pass >= 0 && swapped; pass--){

       swapped = false;
       for(int i = 0; i <= pass - 1 ; i++)
       {
           if(data[i] > data[i + 1]){
               swap(data, i, i + 1);
               swapped = true; 
           }
       }
   }
}

// Add any helper functions(if needed) above.
int* remove_dup(int A[], int sz)
{    /* Alocate the memory of Output array of maximum size n. 
    Fill the new array with unique elements, which have duplicates entries in input array 
    Size of Output array will be less than n. */
    int *output = nullptr;
    // Add your code below this line. Do not modify any other code.
    
    bubble_sort(A, sz); 
    
    int k = 0; 
    output = new int[sz/2]; 
    
    for(int i = 1; i < sz; i++){
        if(A[i] == A[i-1] && output[k] != A[i - 1]){
            output[k] = A[i - 1];
            k++;
        }
    }
    
    for(int i = 0; i < k; i++){
        cout << output[i] << " "; 
    }
    cout << "===" << endl;
    // Add your code above this line. Do not modify any other code.
    return output;
    
}