#include "./../../../../Include/Common.h"


class Solution {
public:
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
};