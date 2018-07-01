#include "./../../../../Include/Common.h"
using namespace std;

// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    // TLE 312/313 -- HashMap solution which is based on a + b = -c
    vector<vector<int>> threeSum_TLE(vector<int>& nums) {
        unordered_map<int, int> hashmap; 
        
        sort(nums.begin(), nums.end());
     
        for(int i = 0; i < nums.size(); i++){
            hashmap.insert(make_pair(nums[i], i));
        }
        
        set<vector<int>> outputSet;         
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(i != j)
                {
                    int sum = nums[i] + nums[j];
                    if(!(hashmap.find(-sum) == hashmap.end()))
                    {                       
                        if(hashmap[-sum] != i && hashmap[-sum] != j){
                            vector<int> line; 
                            line.push_back(nums[i]);
                            line.push_back(nums[j]);
                            line.push_back(-sum);
                            sort(line.begin(), line.end());
                            outputSet.insert(line);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> output;
        set<vector<int>>:: iterator it;
        for( it = outputSet.begin(); it != outputSet.end(); ++it){
             output.push_back(*it);
        }
        return output;
    }
};