#include "./../../../../Include/Common.h"

// 523 . 
// https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySumOrderNSquared(vector<int>& nums, int k) {
        int *presum = new int[nums.size() + 1]; 
        presum[0] = 0; 
        
        // Precalculate sums 
        for(int i = 1; i <= nums.size(); i++){
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        for(int i = 0; i <= nums.size(); i++){
            // At least two numbers must be selected
            for(int j = i + 2; j <= nums.size(); j++){            
                if(k == 0){
                    if(presum[j] == 0 && presum[i] == 0)
                        return true;
                } else if((presum[j] - presum[i]) % k == 0){
                    return true;
                }
            }
        }
        return false;
    }
};