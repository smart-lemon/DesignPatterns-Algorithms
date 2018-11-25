#include "./../../../../Include/Common.h"

// https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
    
    long difference(long a, long b){
        return a > b? (a - b) : (b - a);
    }
    
public:
    // 40/41 sets - then TLE 
    bool containsNearbyAlmostDuplicateTle(vector<int>& nums, int k, int t) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j <= i + k && j <  nums.size(); j++) {
                long diff = 0;
                cout << diff << endl; 

                diff = difference(nums[i], nums[j]);
                if(abs(diff) <= t)
                    return true;
            }
        }
        return false;
    }
};