#include "./../../../../Include/Common.h"

/*
    Find max consecutive ones
    
    https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt = 0;
        int cnt = 0; 

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1){
                cnt++;
                if(cnt > max_cnt)
                    max_cnt = cnt;
            } else {
                cnt = 0;
            }
        }
        return max_cnt;
    }
};