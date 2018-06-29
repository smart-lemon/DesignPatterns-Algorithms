
#include "./../../../../Include/Common.h"


using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    
    int min(int a, int b){
        return a < b? a : b;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int current_length = 0; 
        int min_length = INT_MAX;
        int end_index = 0;
        int sum = 0; 
        
        for(int i = 0; i < nums.size(); i++){
            
            while(sum < s && end_index < nums.size()){
                 sum += nums[end_index];                 
                 end_index++;
                 current_length++;
             }
            
             current_length = end_index - i;
            
            if(current_length < min_length && sum >= s)
                 min_length = current_length;
            
             sum -= nums[i];

        }

        // If there isn't a minimum length, return 0 instead.
        return min_length == INT_MAX ? 0 : min_length;
    }

    int minSubArrayLenAlternative(int s, vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};