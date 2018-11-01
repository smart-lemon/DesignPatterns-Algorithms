#include "./../../../../Include/Common.h"

/*
    Given an array where elements are sorted in ascending order, 
    convert it to a height balanced BST.
    
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

class Solution {
    TreeNode* createSubTree(vector<int>& nums, int low, int high){
        if(low == high){
            return new TreeNode(nums[low]);
        }

        if(low < high){
            int mid = (low + high)/2;
            TreeNode * midNode = new TreeNode(nums[mid]);
            if(low < mid - 1){
                midNode->left = createSubTree(nums, low, mid - 1);
            } 
            if(mid + 1 > high){
                midNode->right = createSubTree(nums, mid + 1, high);
            }
            return midNode;
        }
        return nullptr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        
        TreeNode *dummy = new TreeNode(-1);
        dummy->left = createSubTree(nums, 0, nums.size() - 1);
        return dummy->left;
    }
};



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};