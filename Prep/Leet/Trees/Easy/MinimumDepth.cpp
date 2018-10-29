#include "./../../../../Include/Common.h"

/*
    Find minimum depth of a Binary Tree

    https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
    int min(int a, int b){
        return a < b? a : b;
    }
    
    int minDepthUtil(TreeNode *root){
        // Corner case which should not be called ever
        if(root == nullptr) {
            return 0;
        }
        
        if(root->left == nullptr && root->right == nullptr){
              return  1;
        } 
        if(root->right && root->left == nullptr) {
            return minDepthUtil(root->right) + 1;
        } 
        if(root->left && root->right == nullptr) {
            return minDepthUtil(root->left) + 1;
        } 
        return  min(minDepthUtil(root->left), minDepthUtil(root->right)) + 1;
    }
public:
    int minDepth(TreeNode* root) {

        if(root == nullptr)
           return 0;
        
        return minDepthUtil(root);
    }
};