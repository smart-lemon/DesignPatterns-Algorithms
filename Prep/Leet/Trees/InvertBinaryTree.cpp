#include "./../../../Include/Common.h"
#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// https://leetcode.com/problems/invert-binary-tree  

TreeNode *createNode(int val){
    TreeNode *node = new TreeNode(val);
    return node;
}

class Solution {
public:
    void invertTreeUtil(TreeNode *root, TreeNode *replica) {
        if(root == nullptr){
            return;
        }
        
        if(root) {
            if(root->left) {
                replica->right = createNode(root->left->val);
                invertTreeUtil(root->left, replica->right);
            } else {
                replica->right = nullptr;
            }
            if(root->right) {
                replica->left = createNode(root->right->val);
                invertTreeUtil(root->right, replica->left);
            } else {
                replica->left = nullptr;
            }
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode *replica = createNode(root->val);
        invertTreeUtil(root, replica);
        return replica;
    }
};