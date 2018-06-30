#include "./../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/set-mismatch/

bool comparator (int i,int j) { return (i < j); }

class Solution {
    
    public:

    vector<int> findErrorNums(vector<int>& nums) {
        // Sort the input   
        sort (nums.begin(), nums.end(), comparator); 
        
        vector<int> output;
        int dupe = -1;
        int missing = 1;

        // Find duplicates and missing numbers 
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && (nums[i - 1] == nums[i])) {
               dupe = nums[i];
            }
            
            if(i > 0 && (nums[i] == (nums[i - 1] + 2))){
               missing = nums[i] - 1;
            }
        }
                
        output.push_back(dupe);

        // If missing numbers were not found it must be at the start or the end 
        if(missing == 1 ){
            if(nums[nums.size() - 1] != nums.size())
                output.push_back(nums.size());
            else
                output.push_back(missing); // Missing number was at the start 
        } else {
             output.push_back(missing);
        }
            
        return output;
    }
};