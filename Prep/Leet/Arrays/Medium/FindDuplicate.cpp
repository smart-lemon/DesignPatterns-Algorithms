#include "./../../../../Include/Common.h"

// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int output = -1;
        bool flag = false;
        for(int i = 1; i < sz; i++){
            while(nums[i] == nums[i-1]){
                i++;
                flag = true;
            }
            if(flag)
            {
                output = nums[i - 1];
                return output;
            }
        }
    }
};