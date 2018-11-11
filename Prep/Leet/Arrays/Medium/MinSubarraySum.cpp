
#include "./../../../../Include/Common.h"
/*
    209. Minimum Size Subarray Sum 
    Find the minimal length of a contiguous subarray of which the sum ≥ s. 

    https://leetcode.com/problems/minimum-size-subarray-sum
*/

class Solution {
public:
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
}