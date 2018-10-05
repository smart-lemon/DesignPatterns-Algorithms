#include "./../../../../Include/Common.h"

/*
    416. Partition Equal Subset Sum
    https://leetcode.com/problems/partition-equal-subset-sum
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, target = 0;
        int sz = nums.size(); 
        if(sz == 0)
            return false; 

        for(int i = 0; i < sz; i++)
            sum += nums[i]; 
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
                    if(j - nums[i] >= 0)
                        left = DP[i - 1][j - nums[i]];
                }
                DP[i][j] = up || left;
            }
        }
        return DP[sz - 1][target] ;
    }
};