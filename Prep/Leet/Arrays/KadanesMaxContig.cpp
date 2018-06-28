#include "./../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int max(int a, int b){
        return a > b? a : b;
    }
    
    int maxSubArray(vector<int>& nums) {
        int max_current, max_overall;
        max_current = max_overall = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            max_current = max(nums[i], max_current + nums[i]); 
            if(max_current > max_overall)
                max_overall = max_current;
        }
        return max_overall;
    }
};