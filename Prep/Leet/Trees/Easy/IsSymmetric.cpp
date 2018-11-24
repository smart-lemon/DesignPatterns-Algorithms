#include "./../../../../Include/Common.h"
typedef struct TreeNode;

/*
      Symmetric Tree: Check whether the binary tree is a mirror of itself 
    (ie, symmetric around its center).


    
*/
class Solution {
public:
    bool isSymmetricUtil(TreeNode* rootLeft, TreeNode* rootRight){
        // Leaf nodes
        if(rootLeft == nullptr && rootRight == nullptr)
            return true;

        if(rootLeft && rootRight && rootLeft->val == rootRight->val && 
             isSymmetricUtil(rootLeft->left, rootRight->right) && 
             isSymmetricUtil(rootLeft->right, rootRight->left))
            return true;
        else
            return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetricUtil(root->left, root->right);
    }
};

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
