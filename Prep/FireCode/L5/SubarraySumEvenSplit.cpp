#include "./../../../Include/Common.h"

/*
    Write a function to determine if it is possible to split
    an array of integers arr with its size sz into two parts 
    such that the sum of all integers in each part is the same

    split_array({1,2,3,4},3) ==> true
    split_array({1,2,4},3) ==> false

*/
bool split_array(int arr[], int sz) {
    int sum = 0, target = 0;
    if(sz == 0)
        return false; 

    for(int i = 0; i < sz; i++)
        sum += arr[i]; 
    if(sum % 2 != 0)
        return false; 
    target = sum/2; 
    
    vector<vector<bool>> DP(sz, vector<bool>(target + 1, false));
    
    for(int i = 0; i < sz; i++)
        DP[i][0] = true; 
    
    for(int i = 1; i < sz; i++) {
        for(int j = 1; j <= target; j++) {
            bool up = false, left = false;
            if(i - 1 >= 0) {
                up = DP[i - 1][j];
                if(j - arr[i] >= 0)
                    left = DP[i - 1][j - arr[i]];
            }
            DP[i][j] = up || left;
        }
    }
    return DP[sz - 1][target] ;
}