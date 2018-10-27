#include "./../../../../Include/Common.h"
typedef struct TreeNode;

/*
    Given a binary tree, determine if it is height-balanced.    
    
    https://leetcode.com/problems/balanced-binary-tree
*/

class Solution {
    int isBalancedUtil(TreeNode* root, int min, int max) {
        if(root == nullptr)
            return 0;

        if(root->val < min || root->val > max)
            return -1;

        int leftHt = isBalancedUtil(root->left, min, root->val);
        int rightHt = isBalancedUtil(root->right, root->val, max);
       

        if(leftHt == -1 || rightHt == -1)
            return  -1; 
        else {
            if(abs(leftHt - rightHt) <= 1)
                return leftHt > rightHt? leftHt + 1: rightHt + 1;
            else 
                return -1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedUtil(root, INT_MIN, INT_MAX) != -1;
    }
};


typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
