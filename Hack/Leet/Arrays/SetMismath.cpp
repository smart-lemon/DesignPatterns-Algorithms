#include "./../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>


bool comparator (int i,int j) { return (i < j); }

class Solution {
    
    public:

    vector<int> findErrorNums(vector<int>& nums) {
        // Sort the input   
        sort (nums.begin(), nums.end(), comparator); 
        
        vector<int> output;
        int dupe = -1;
        int missing = 1;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && (nums[i - 1] == nums[i])) {
                cout << "<Dupe at " << i << ">" << endl;
               dupe = nums[i];
            }
            
            if(i > 0 && (nums[i] == (nums[i - 1] + 2))){
               cout << " Missing at " << i << endl;
               missing = nums[i] - 1;
            }
        }
                
        output.push_back(dupe);
        if(missing == 1 ){
            if(nums[nums.size() - 1] != nums.size())
                output.push_back(nums.size());
            else
                output.push_back(missing); 
        } else {
             output.push_back(missing);
        }
            
        return output;
    }
};