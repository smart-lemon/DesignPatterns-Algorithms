#include "./../../../../Include/Common.h"

/*
    215. Kth Largest Element in an Array
    https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution {
    
    int partition(vector<int> & nums, int l, int h, int & ans, int k){
        int partition_by = nums[l], p_index = l; 
        int left = l, right = h;
        
        while(left < right) {
            while(left < nums.size() && nums[left] <= partition_by)
                left++;
            while(right >= l && nums[right] > partition_by)
                right++; 
            
            swap(nums[left], nums[right]); 
        }
        swap(nums[p_index], nums[right]); 
        if(p_index == k)
            ans = nums[k];
        return p_index; 
    }
    
    void kthSort(vector<int>& nums, int l, int h, int & ans, int k){
        while(l < h) {
            int index = partition(nums, l, h, ans, k);
            if(ans != -1)
                return; 
            kthSort(nums, l, index - 1, ans, k); 
            kthSort(nums, index, h, ans, k);
        }
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = -1;
        kthSort(nums, 0, nums.size() - 1, ans, k);
        return ans; 
        
    }
};