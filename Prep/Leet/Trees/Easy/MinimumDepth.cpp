#include "./../../../../Include/Common.h"
#include <iostream>

using namespace std;

/**
 * Find minimum depth of a subtree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
    int min(int a, int b){
        return a < b? a : b;
    }
    
    int minDepthUtil(TreeNode *root){
        if(root == nullptr) {
            return INT_MAX;
        }
        
        if(root->left == nullptr && root->right == nullptr){
              return  1;
        } else if(root->right || root->left) {
            return min(minDepthUtil(root->left), minDepthUtil(root->right)) + 1;
        } 
        return 0;
    }
public:
    int minDepth(TreeNode* root) {
        int left = 0; int right = 0;
        if(root == nullptr)
           return 0;
        return minDepthUtil(root);
    }
};