#include "./../../../../Include/Common.h"

/*
    Array Partition I

    https://leetcode.com/problems/array-partition-i/description/
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, j = 1; j < nums.size(); i += 2, j += 2){
            ans += min(nums[i], nums[j]); 
        }
        return ans; 
    }
};