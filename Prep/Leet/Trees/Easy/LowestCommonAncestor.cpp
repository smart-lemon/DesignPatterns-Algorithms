#include "./../../../../Include/Common.h"


/*
    Find the lowest common ancestor (LCA) of two given nodes in the BST.
    
    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr; 

        if(root->val == p->val)
            return p;
         if(root->val == q->val)
            return q;

        TreeNode *left = nullptr, *right = nullptr; 
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);

        if(left && right){
            return root; 
        }
        if(left) {
            return left;
        } 
        if(right) {
            return right;
        }
        return nullptr;
    }
};