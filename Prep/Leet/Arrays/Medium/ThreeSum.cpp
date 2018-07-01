#include "./../../../../Include/Common.h"

using namespace std;

// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        set<vector<int>> outputSet;
        
        sort(nums.begin(), nums.end());
     
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]] = i;
        }
        
        int i = 0, j = i + 1;
        while(i < nums.size()){
            while(j < nums.size()){
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
                j = hashmap[nums[j]] + 1;
            }
            i = hashmap[nums[i]] + 1;
            j = i + 1;
        }
        
        vector<vector<int>> output;
        set<vector<int>>:: iterator it;
        for( it = outputSet.begin(); it != outputSet.end(); ++it){
             output.push_back(*it);
        }

        return output;
    }
};