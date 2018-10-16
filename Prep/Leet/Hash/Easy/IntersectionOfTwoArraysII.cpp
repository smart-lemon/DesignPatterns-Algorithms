#include "./../../Include/Common.h"

/* 
    350. Intersection of Two Arrays II
    
    https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap; 
        vector<int> res; 
        
        vector<int> &longer  = nums1.size() >= nums2.size() ? nums1 : nums2; 
        vector<int> &shorter = nums1.size() >= nums2.size() ? nums2 : nums1; 
        
        for(int i = 0; i < longer.size(); i++){
            hashmap[longer[i]]++;
        }
        
        for(int i = 0; i < shorter.size(); i++){
            if( hashmap.find(shorter[i]) != hashmap.end() && hashmap[shorter[i]] > 0){
                hashmap[shorter[i]]--;
                res.push_back(shorter[i]);
            }
        }
        return res;        
    }
};