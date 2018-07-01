// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
    TreeNode *recursiveLca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr)
            return nullptr;
        
        TreeNode *leftFound = recursiveLca(root->left, p, q);
        TreeNode *rightFound = recursiveLca(root->right, p, q);
        
        if(leftFound && rightFound)
            return root;
        
        if(root == p || root == q)
            return root;
        
        return leftFound? leftFound : rightFound; 
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr)
            return nullptr;
        return recursiveLca(root,  p, q);
    }
};