/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    
     vector<int> contatenate(vector<int> a, vector<int> b){
        vector<int> ab;
        ab.reserve( a.size() + b.size());
        ab.insert( ab.end(), a.begin(), a.end());
        ab.insert( ab.end(), b.begin(), b.end());
        return ab; 
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        // Output
        vector<int> out;

        if(root == nullptr)
        {
            return out;
        }
        vector<int> left, right;
        
        // Left 
        left = postorderTraversal(root->left);
        if(left.size() > 0)
            out = contatenate(out, left);

        // Right 
        right = postorderTraversal(root->right);
        if(right.size() > 0)
            out = contatenate(out, right);
        
        // Middle
        out.push_back(root->val);
        
        return out;
    }
};