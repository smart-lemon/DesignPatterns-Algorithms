#include "./../../../../Include/Common.h"
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

class Solution {
    
    int sumRecursive(TreeNode *root, int parent) {
        
        // Leaf - the answer is sum of all of the leafs 
        if(root && root->left == nullptr && root->right == nullptr) {             
            cout << "Leaf : " << root->val << " Parent:  " << parent << endl;
            return parent; 
        }
        cout << "Root : " << root->val << " Parent " << parent << endl;
        int sumOfLeft = 0, sumOfRight = 0;
        
        if(root->left)
            sumOfLeft = sumRecursive(root->left, (parent * 10) + root->left->val);
        if(root->right)
            sumOfRight = sumRecursive(root->right, (parent * 10) + root->right->val);
        
        return sumOfLeft + sumOfRight;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0; 
        
        return sumRecursive(root, root->val);
    }
};