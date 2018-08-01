#include "./../../../../Include/Common.h"

// 740.
// https://leetcode.com/problems/delete-and-earn/


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // The range of these numbers is [1, 10000]
        int n = 10001;
        int sumOfNum[10001] = {0, };

        for(int valOfNumAtIndex: nums){
            sumOfNum[valOfNumAtIndex] += valOfNumAtIndex;
        }

        /*
            take[i] = skip[i-1] + values[i];
            skip[i] = Math.max(skip[i-1], take[i-1]);
        */
       int take = 0, skip = 0;
       for(int i = 0; i < n; i++){
           int newTake = max(skip + sumOfNum[i], take);
           skip = take;
           take = newTake;
       }
    
        return max(take,  skip);
    
    }
};