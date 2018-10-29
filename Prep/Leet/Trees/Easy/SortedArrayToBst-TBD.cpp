#include "./../../../../Include/Common.h"

/*
    Given an array where elements are sorted in ascending order, 
    convert it to a height balanced BST.
    
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    }
};



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};