#include "./../../../../Include/Common.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<string> output; 
    
public:
    
    void binaryTreePaths(TreeNode *root, string t){
        
        if(root == nullptr)
            return;
        
        if(root && root->left == nullptr && root->right == nullptr){
            output.push_back(t);
            return;
        }        
        if(root->left) 
            binaryTreePaths(root->left, t + "->" + to_string(root->left->val));     
        if(root->right) 
            binaryTreePaths(root->right, t + "->" + to_string(root->right->val));
     
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return  output;
        binaryTreePaths(root, to_string(root->val));
        return output;
    }
};