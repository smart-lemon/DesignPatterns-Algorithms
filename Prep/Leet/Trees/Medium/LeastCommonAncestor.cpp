struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

 // Not yet solved 

class Solution {
    
    TreeNode *recursiveLca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr)
            return nullptr;
        
        if(root == p || root == q)
            return root;
        
        
        TreeNode *leftFound = recursiveLca(root->left, p, q);
        TreeNode *rightFound = recursiveLca(root->right, p, q);
        
        if(leftFound && rightFound)
            return root;
        
        return nullptr; 
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recursiveLca(root,  p, q);
    }
};