bool comparator (int i,int j) { return (i < j); }

// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        sort (nums.begin(), nums.end(), comparator); 

        // Find missing numbers 
        for(int i = 0; i < nums.size(); i++){
                        
            if(i > 0 && (nums[i] == (nums[i - 1] + 2))){
               missing = nums[i] - 1;
            }
        }

        if(missing == 0){
             if(nums[nums.size() - 1] != nums.size())
                return nums.size();
        }
        
        return missing;
    }
};