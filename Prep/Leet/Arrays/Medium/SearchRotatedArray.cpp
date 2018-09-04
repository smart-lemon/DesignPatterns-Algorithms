#include "./../../../../Include/Common.h"

/*
   33. Search in Rotated Sorted Array
   https://leetcode.com/problems/search-in-rotated-sorted-array
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, m, r = nums.size() - 1;
        int key = target;

        while(l <= r) {
            m = (l + r) / 2;
            // Check if m is the solution
            if(nums[m] == target)
                return m;

            // Bottom half is sorted. Inculde l, as m is already checked
            if(nums[l] <= nums[m]){
                 if(nums[l] <= key && key < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            // Upper half is sorted. Inculde r, as m is already checked
            } else {
                if(nums[m] < key && key <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return - 1;
    }
};

// Details : https://articles.leetcode.com/searching-element-in-rotated-array/