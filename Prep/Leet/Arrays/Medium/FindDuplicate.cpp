#include "./../../../../Include/Common.h"

// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:

    // N-squared approach
    int findDuplicateNdsquared(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int output = -1;
        bool found_flag = false;

        for(int i = 1; i < sz; i++){
            while(nums[i] == nums[i-1]){
                i++;
                found_flag = true;
            }
            if(found_flag)
            {
                output = nums[i - 1];
                return output;
            }
        }
    }

    // Explanation 
    // http://keithschwarz.com/interesting/code/?dir=find-duplicate

    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int find = 0;
        while(slow != find){
            slow = nums[slow];
            find = nums[find];
        }
        return find;
    }

};