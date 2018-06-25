#include "./../../../Include/Common.h"
#include <iostream>
#include <vector>

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


// https://leetcode.com/problems/binary-tree-inorder-traversal

// Inorder traversal : Left - Middle - Right 
class Solution {
public:
    vector<int> contatenate(vector<int> a, vector<int> b){
        vector<int> ab;
        ab.reserve( a.size() + b.size());
        ab.insert( ab.end(), a.begin(), a.end());
        ab.insert( ab.end(), b.begin(), b.end());
        return ab; 
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        // Output
        vector<int> out;

        if(root == nullptr)
        {
            return out;
        }
        vector<int> left, right;

        // Left 
        left = inorderTraversal(root->left);
        
        // Middle 
        if(left.size() >= 0)
            left.push_back(root->val);

        // Right 
        right = inorderTraversal(root->right);
        if(right.size() >= 0)
            out = contatenate(left, right);

        return out;
    }
};