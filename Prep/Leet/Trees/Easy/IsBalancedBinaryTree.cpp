#include "./../../../../Include/Common.h"
typedef struct TreeNode;

/*
    Given a binary tree, determine if it is height-balanced.    
    
    https://leetcode.com/problems/balanced-binary-tree
*/

typedef struct TreeNode;

class Solution {
    int isBalancedUtil(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int leftHt = isBalancedUtil(root->left);
        int rightHt = isBalancedUtil(root->right);
        if(leftHt == -1 || rightHt == -1)
            return -1;
        if(abs(leftHt - rightHt) <= 1)
                return leftHt > rightHt? leftHt + 1: rightHt + 1;
            else 
                return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedUtil(root) != -1;
    }

    ///////////////////////////////////////////////////////////////////////////////
    int height(TreeNode *root) {
			if(root == nullptr)return 0;
			return max(height(root->left), height(root->right)) + 1;
		}
		bool isBalanced(TreeNode* root) {
			if(root == nullptr) return true;
			return isBalanced(root->left) && isBalanced(root->right) 
                   && abs(height(root->left) - height(root->right)) <= 1;
		}
};


typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
