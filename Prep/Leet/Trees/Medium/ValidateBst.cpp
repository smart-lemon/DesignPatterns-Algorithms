#include "./../../../../Include/Common.h"

/**
 *  https://leetcode.com/problems/validate-binary-search-tree/description/
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
    
bool do_validate_bst( TreeNode* root,
                      TreeNode *left_ancestor = nullptr, 
                      TreeNode *right_ancestor = nullptr )
{
    if(root == nullptr) {
        return true; // leaf
    }
    
    if(right_ancestor && root->val >= right_ancestor->val){
        return false; 
    }
    
    if(left_ancestor && root->val <= left_ancestor->val){
           return false; 
    }
    
    return do_validate_bst(root->left, left_ancestor, root) && 
           do_validate_bst(root->right, root, right_ancestor); 
}

public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;

        return do_validate_bst(root);
    }
};