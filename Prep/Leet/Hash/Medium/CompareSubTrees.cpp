#include "./../../../../Include/Common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, TreeNode*> hashmap;
    vector<TreeNode*> result; 
    
    bool compareTrees(TreeNode *a, TreeNode *b){
        if(!a && !b)
            return true;
        
        if(a->val == b->val){
            return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
        } else {
            return false; 
        }
        return false;
    }


    void inorderTraversal(TreeNode* root) {
        
        // Output
        if(root == nullptr){
            return;
        }

        // Left 
        inorderTraversal(root->left);
        
        // Insert into hashmap and check

        // Right 
        inorderTraversal(root->right);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
    }
};