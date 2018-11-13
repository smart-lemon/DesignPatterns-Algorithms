#include "./../../../../Include/Common.h"

/*
    Given an array nums, write a function to move all 0's to the end of it
    while maintaining the relative order of the non-zero elements.


*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCnt = 0;
        int left = 0, right = 0, sz = nums.size();

        while(true) {
            while(left < sz && nums[left] != 0){
                left++;
            }

            while(right < sz && nums[right] == 0){
                right++;
            }

            nums[left] = nums[right];
            nums[right] = 0;
            left++;

            if(right == sz -1)
                break;
        }
    }
};

/*
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
*/