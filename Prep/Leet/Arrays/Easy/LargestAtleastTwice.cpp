#include "./../../../../Include/Common.h"

//
//

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0, max_div_by_2 = 0, max_index = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max){
                max = nums[i];
                max_index = i;
            }
        }
        
        max_div_by_2 = max / 2;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i != max_index) {
                if(nums[i] > max_div_by_2)  
                    return -1; 
            }
        }
        return max_index; 
    }
};