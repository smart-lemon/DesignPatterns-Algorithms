#include "./../../../Include/Common.h"

/*
    Two Sum 
    
    https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        ret.reserve(2);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
    }
};

/*
    Test Code

    std::vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(11);
    a.push_back(15);
    Solution s;
    auto r = s.twoSum(a, 9);
    for(int i = 0; i < r.size(); i++){
         cout << r[i] << " ";
    }
*/
