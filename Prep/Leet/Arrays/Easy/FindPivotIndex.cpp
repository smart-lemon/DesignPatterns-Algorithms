// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int cumsum = 0, sum = 0; 
        
        // Calculate cumulative sum 
        for(int i = 0; i < nums.size(); i++)
            cumsum += nums[i];
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            int left = sum - nums[i];
            int right = cumsum - sum; 

            // Equivalent check : sum * 2 == cumsum - nums[i]
            if(left == right){
                return i; 
            }
        }
        
        return -1;        
    }
};