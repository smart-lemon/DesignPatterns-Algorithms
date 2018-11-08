#include "./../../../../Include/Common.h"

/*
    Contains Duplicate - II
    
    https://leetcode.com/problems/contains-duplicate-ii/
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j <= i + k && j <  nums.size(); j++)
                if(nums[i] == nums[j])
                    return true;
        }
        return false;
    }

    bool containsNearbyDuplicateFaster(vector<int>& nums, int k)
    {
       std::unordered_set<int> s;
       
       if (k <= 0) return 
            false;

       if (k >= nums.size()) k = nums.size() - 1;
       
       // The basic idea is to maintain a set s which contain unique values 
       // from nums[i - k] to nums[i - 1], and search in the set
       // Update the set at you go by removing nums[i - k] and adding nums[i]
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};