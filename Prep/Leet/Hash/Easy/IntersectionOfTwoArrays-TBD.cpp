#include "./../../Include/Common.h"

/* 
    349. Intersection of Two Arrays

    https://leetcode.com/problems/intersection-of-two-arrays/
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        vector<int> ans;
        unordered_set<int> hashset; 
        if(!n1 || !n2)
            return ans;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, k = 0; 
        
        while(i < n1 && j < n2){
            if(nums1[i] == nums2[j]){
                hashset.insert(nums1[i]);
                i++; j++;
                cout << nums1[i] << " ";
            } else if(nums1[i] < nums2[j]){
                i++;
            } else{
                j++;
            }
        }
        // Convert hashset to vector
        ans.insert(ans.end(), hashset.begin(), hashset.end());

        return ans;
    }

    // Without sorting 
    vector<int> intersectionFaster(vector<int>& nums1, vector<int>& nums2) {
        
        // Add one of the arrays to a hashset
        unordered_set<int> hashset(nums1.begin(), nums1.end());
        
        vector<int> res;
        for (auto a : nums2)
            if (hashset.count(a)) {
                res.push_back(a);
                hashset.erase(a);
            }
        return res;
    }
};