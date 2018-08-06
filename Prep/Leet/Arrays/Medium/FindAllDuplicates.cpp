#include "./../../../../Include/Common.h"


class Solution {
public:

    // O(N^2) 
    vector<int> findDuplicates(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         
         vector<int> output;
         bool flag = false;
         for(int i = 1; i < nums.size(); i++){
            while(nums[i] == nums[i-1]){
                i++;
                flag = true;
            }
            if(flag)
            {
                output.push_back(nums[i - 1]);
                flag = false;
            }
         }  
        return output;
    }

    // O(N)
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) res.push_back(nums[i]);
        }
        return res;
    }
};