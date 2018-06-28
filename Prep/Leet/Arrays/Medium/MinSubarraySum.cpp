 // TBD 
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
                 sum += nums[end_index++];
                 current_length++;
             }
            
             if(current_length < min_length)
                 min_length = current_length;
            
             sum -= nums[i];
             current_length = current_length - 1;
        }
        // If there isn't a minimum length, return 0 instead.
        return min_length == INT_MAX ? 0 : min_length;
    }
};