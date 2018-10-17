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
        while(node->left){
            node = node->left;
        } 
        return node;
    }
    
    TreeNode* deleteUtil(TreeNode* root, int key) {
        if (!root) return root;    
        if (root->val > key)
            root->left = deleteUtil(root->left, key);
        else if (root->val < key)
            root->right = deleteUtil(root->right, key);
        else {
            if (!root->left) {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                // Find the inorder successor (the minimal node in right subtree)
                TreeNode* successor = findInorderSuccessor(root->right); 
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        deleteUtil(root, key);
        return root;
    }
};