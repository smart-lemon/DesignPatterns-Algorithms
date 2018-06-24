#include "./../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
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
        vector<int> out;
        if(root == nullptr)
        {
            return out;
        }
        vector<int> left, right;

        left = inorderTraversal(root->left);
        if(left.size() >= 0)
            left.push_back(root->val);
        right = inorderTraversal(root->right);
        
        if(right.size() >= 0)
            out = contatenate(left, right);
        return out;
    }
};