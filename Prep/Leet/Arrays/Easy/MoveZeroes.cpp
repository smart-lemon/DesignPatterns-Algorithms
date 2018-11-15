#include "./../../../../Include/Common.h"

/*
    283. Move Zeroes: Given an array nums, write a function to move all 0's to the end of it
    while maintaining the relative order of the non-zero elements.

    https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, sz = nums.size();

        while(true) {
            // left points to next occurance of zero
            while(left < sz && nums[left] != 0){
                left++;
            }

            // right points to next occurance of non-zero
            while(right < sz && nums[right] == 0){
                right++;
            }

            // Exit condition 
            if(right >= sz || left >= sz)
                break;

            // Swap -- kinda
            if( left <= right ){
                nums[left] = nums[right];
                nums[right] = 0;
                left++;
            } else {
                right = left;
            }
        }
    }

    void moveZeroes(vector<int>& nums) {
        int left = 0;
        // Move all the nonzero elements advance
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
        }
        for (;left < nums.size(); left++) {
            nums[left] = 0;
        }
    }
};

/*
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
*/