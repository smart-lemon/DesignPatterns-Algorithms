#include "./../../Include/Common.h"

/* 
    136. Single Number : Every element appears twice except for one. 
    Find that single one.

    https://leetcode.com/problems/single-number/description/    
*/

class Solution {
public:
    int singleNumberWithMemory(vector<int>& nums) {
        unordered_map<int, int> hashmap; 
        
        for(int num : nums){
            hashmap[num]++;
        }
        for(int num : nums){
            if(hashmap[num] == 1)
                return num;
        }
        return 0; 
    }

    int singleNumber(vector<int>& nums) {
         int num = 0;
         
         // Since all the numbers are duplicates, they will cancel out each other
         // Leaving the lonely number
         for (int i = 0; i < nums.size(); ++i) {
             num ^= nums[i];
         }      
        return num; 
    }
};