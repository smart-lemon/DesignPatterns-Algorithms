/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    int min(int a, int b){
        return a < b? a : b;
    }
    
    int minDepthUtil(TreeNode *root, int depth){
        int left = 0, right = 0;
        if(root) {
            left = minDepthUtil(root->left, depth + 1);
            right = minDepthUtil(root->right, depth + 1);
            return min(left, right);
        } else {
            return depth;
        }
    }
public:
    int minDepth(TreeNode* root) {
        int left = 0; int right = 0;
        
        return minDepthUtil(root, 0);
    }
};