/*
    Write a function to determine if it is possible to choose a subset of elements from a given array
    such that the sum of all numbers in the subset is equal to a given target.
*/



// Swap position a with b in an array of integer numbers
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


// Note to self: Not yet handled negative numbers 
bool group_sum_with_num_nonnegative(int arr[], int sz, int must_have, int target_sum)
{
    int target = target_sum; 
    if(sz == 0)
        return false; 
    bubble_sort(arr, sz);
    bool **DP;
    DP = new bool*[sz];
    for(int i = 0; i < sz; i++){
        DP[i] = new bool[target + 1]{false};
    }
        
    for(int i = 0; i < sz; i++)
        DP[i][0] = true;
        
    for(int i = 0; i < sz; i++){
        for(int j = 1; j <= target; j++){
            if(i - 1 >= 0){
                if(DP[i - 1][j])
                    DP[i][j] = true;
            }
            if( !DP[i][j] && DP[i - 1][j - arr[i]])
                 DP[i][j] = true;
            else
                DP[i][j] = false;
        }
    }

    return DP[sz - 1][target];
}
// Approach : Power set 
// https://www.coderbyte.com/algorithm/subset-sum-problem-revised
// O(2^n)