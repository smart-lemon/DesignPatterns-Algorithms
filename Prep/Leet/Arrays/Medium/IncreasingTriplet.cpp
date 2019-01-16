
#include "./../../../../Include/Common.h"

/*
    Given an unsorted array return whether an increasing subsequence of length 3 
    exists or not in the array.

*/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, middle = INT_MAX;
        for (int n : nums) {
            if (n <= small)     
                small = n;  // 
            else if (n <= middle)   
                middle = n;  // update middle only if greater than small but smaller than big
            else 
                return true; // return if you find a number bigger than both
        }
        return false;
    }
};

/*
    Clever use of conditional statement
*/