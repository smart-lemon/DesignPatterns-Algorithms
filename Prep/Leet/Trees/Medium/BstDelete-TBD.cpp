#include "./../../../../Include/Common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 
    450. Delete Node in a BST
    Given a root node of a BST and a key, delete the node with the given key in the BST. 
    Return the root node of the BST.

    https://leetcode.com/problems/delete-node-in-a-bst/
*/



class Solution {
    TreeNode *findInorderSuccessor(TreeNode *node) {
        while(node->right){
            node = node->right;
        } 
        return node;
    }

    void deleteUtil(TreeNode *root, int key) {
        if(!root)
            return;
        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr) {
                root = nullptr;
                return;
            } else if(root->left && root->right) {
                TreeNode *successor = findInorderSuccessor(root->right);
                if(successor != nullptr){
                    root->val = successor->val;
                    successor = nullptr;
                }
            } else {
                 if(root->left){
                    root = root->left;
                    root->left = nullptr;
                }  else {
                    root = root->right;
                    root->right = nullptr;
                }
            }
        } else {
            deleteUtil(root->right, key);
            deleteUtil(root->left, key);
        }
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        deleteUtil(root, key);
        return root;
    }
};