/*
    Write a function to determine if it is possible to choose a subset of elements from a given array
    such that the sum of all numbers in the subset is equal to a given target.
*/

// Note to self: Not yet handled negative numbers and it seems i have to get arr sorted first
bool group_sum_with_num(int arr[], int sz, int must_have, int target_sum)
{
    int target = target_sum; 
    bool **DP;
    DP = new bool*[sz];
    for(int i = 0; i < sz; i++)
        DP[i] = new bool[target + 1];
        
    for(int i = 0; i < sz; i++)
        DP[i][0] = false;
        
    for(int i = 0; i < sz; i++){
        for(int j = 1; j <= target; j++){
            if(i - 1 >= 0){
                if(DP[i - 1][j])
                    DP[i][j] = true;
            }
            if( DP[i][j] && DP[i][j - arr[i]])
                 DP[i][j] = true;
            else
                DP[i][j] = false;
        }
    }

    return DP[sz - 1][target];
}