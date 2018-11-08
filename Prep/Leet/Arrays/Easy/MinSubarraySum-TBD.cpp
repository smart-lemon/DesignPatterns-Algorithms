#include "./../../../../Include/Common.h"

/*
    Find the minimal length of a contiguous subarray of which the sum ≥ s

    https://leetcode.com/problems/minimum-size-subarray-sum/
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> presum(nums.size(), 0);

        if(nums.size() == 0)
            return 0;

        presum[0] = nums[0];
        if(presum[0] >= s)
            return 1;

        for(int i = 1; i < nums.size(); i++) {
            presum[i] = nums[i] + presum[i - 1];
        }
        
        int left = -1, mini = INT_MAX, left_presum;
        for(int i = 0; i < nums.size(); i++) {
            left_presum = 0;
            if(presum[i] - left_presum >= s){
                if(left >= 0)
                    left_presum = presum[left];
                if(left >= 0 && i - left < mini)
                    mini = i - left;
                left++;
            } 
        }
        return mini;
    }
};