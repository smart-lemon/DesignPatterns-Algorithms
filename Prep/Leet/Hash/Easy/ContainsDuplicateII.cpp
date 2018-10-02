
#include "./../../Include/Common.h"

/*
    219. Contains Duplicate II
    
    https://leetcode.com/problems/contains-duplicate-ii/description/
*/


class Solution {
public:
    // TLE 
    bool containsNearbyDuplicateTle(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j <= i + k && j < nums.size(); j++)
                if(nums[i] == nums[j])
                    return true;
        }
        return false;
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap; 
            
        for(int i = 0; i < nums.size(); i++)
        {
            if(hashmap.count(nums[i]) > 0 && i - hashmap[nums[i]] <= k)
                return true; 
            hashmap[nums[i]] = i;

        }
        return false;
    }
};