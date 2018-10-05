#include "./../../../../Include/Common.h"


using namespace std;

// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    
    int max(int a, int b){
        return a > b? a : b;
    }
    
    int maxSubArray(vector<int>& nums) {
        int max_current, max_overall;
        
        if(nums.size() == 0)
            return 0;

        // 1. Define max_current and max_overall as the first element
        max_current = max_overall = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            // 2. The current local maximum can be the current element or 
            // the current local maximum including the current element
            max_current = max(nums[i], max_current + nums[i]); 

            // 3. Update the overall maximum with the best local maximum so far 
            if(max_current > max_overall)
                max_overall = max_current;
        }
        return max_overall;
    }
};