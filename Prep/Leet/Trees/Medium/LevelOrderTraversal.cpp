#include "./../../../../Include/Common.h"

/* 
    102. Binary Tree Level Order Traversal
    https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        vector<vector<int>> res;
        vector<int> output; 
        
        if(root == nullptr)
            return res;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node != nullptr) {
                output.push_back(node->val);                
            }  else {
                res.push_back(output);
                output.clear();
                
                // Only add null marker if there is something in the queue
                if (q.size() > 0) {
                    q.push(nullptr);
                }
                continue;
            }

            if(node && node->left)
                q.push(node->left);

            if(node && node->right)
                q.push(node->right);
        };
        return res; 
    }
};