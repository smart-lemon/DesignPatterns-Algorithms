/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode.com/problems/binary-tree-preorder-traversal 

class Solution {
public:
    
     vector<int> contatenate(vector<int> a, vector<int> b){
        vector<int> ab;
        ab.reserve( a.size() + b.size());
        ab.insert( ab.end(), a.begin(), a.end());
        ab.insert( ab.end(), b.begin(), b.end());
        return ab; 
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        // Output
        vector<int> out;

        if(root == nullptr)
        {
            return out;
        }
        vector<int> left, right;
        
        // Middle 
        out.push_back(root->val);
        
        // Left 
        left = preorderTraversal(root->left);
        if(left.size() > 0)
            out = contatenate(out, left);

        // Right 
        right = preorderTraversal(root->right);
        if(right.size() > 0)
            out = contatenate(out, right);

        return out;
    }
};