
#include "./../../../../Include/Common.h"


using namespace std;

// https://leetcode.com/problems/array-partition-i 


class Solution {
     int min(int a, int b){
        return a < b? a : b;
    }
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int i = 0, sum = 0; 
        while (i < len){
            sum += min(nums[i], nums[i+1]);
            i += 2;
        }
        
        return sum; 
    }
};