#include "./../../../../Include/Common.h"

/* 
    217. Contains Duplicate
    https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset; 
        
        for(int number : nums){
            if(hashset.count(number) > 0){
                return true; 
            } else {
                hashset.insert(number);
            }
        }
        return false; 
    }
};