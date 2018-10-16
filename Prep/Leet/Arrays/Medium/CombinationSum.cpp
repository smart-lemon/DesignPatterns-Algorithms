
#include "./../../../../Include/Common.h"

// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution {
    vector<vector<int>> output;
    vector<int> input;
    int targetSum;


public:
    void permute_combinationSum(vector<int>& result, int pos, int sum){
        if(pos >= input.size()) {
            return;
        }
                
        // Reached the desired sum
        if(sum == targetSum){
            output.push_back(result);
            return;
        } else if (sum > targetSum) {
            return;
        }
        
        //  Not including pos
        permute_combinationSum(result, pos + 1 , sum);
       
        // Including pos
        result.push_back(input[pos]);
        permute_combinationSum(result, pos, sum + input[pos]);
        result.pop_back();
       
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        input = candidates;
        targetSum = target;
        
        vector<int> result;
        permute_combinationSum(result, 0, 0);
        return output;
    }
};