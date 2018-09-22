#include "./../../../../Include/Common.h"

/**
     https://leetcode.com/problems/validate-binary-search-tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 
    If we were to do an inorder traversal, 
    then the ancestor will be node which came before or after the current node during the inorder traversal
       * left ancestor or predessor = the node that came before the current node during inorder traversal 
       * right ancestor =  
*/

class Solution {  
    
bool do_validate_bst( TreeNode* root,
                      TreeNode *left_ancestor = nullptr, 
                      TreeNode *right_ancestor = nullptr )
{
    if(root == nullptr) {
        return true; // leaf
    }
    
    // The root should be lesser than it's right inorder ancestor. 
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