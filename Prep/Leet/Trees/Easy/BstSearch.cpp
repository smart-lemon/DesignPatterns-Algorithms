#include "./../../../../Include/Common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 
    700. Search in a Binary Search Tree
    Find the node in the BST that the node's value equals the given value. 
    Return the subtree rooted with that node. 

    https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
        if(root->val > val){
            return searchBST(root->left, val);
        } else if (root->val < val){
            return searchBST(root->right, val);
        } else {
            return root;
        }
    }
};