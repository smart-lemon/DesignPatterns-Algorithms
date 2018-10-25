#include "./../../../../Include/Common.h"

/*
    220. Contains Duplicate III
    
    Find out whether there are two distinct indices i and j in the array such that the absolute difference 
    between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k
    
    https://leetcode.com/problems/contains-duplicate-iii/description/
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
                
        map<long long,int> hashmap;
        for (int r = 0, l = 0;r < nums.size(); r++) {
            
            if (r - l > k && hashmap[nums[l]] == l)
                hashmap.erase(nums[l++]);
            
            auto it = hashmap.lower_bound((long long)nums[r] - t);
            if (it != hashmap.end() && abs((long long)it->first - nums[r]) <= t)
                return true;
            hashmap[nums[r]] = r;
        }
        return false;
    }
};