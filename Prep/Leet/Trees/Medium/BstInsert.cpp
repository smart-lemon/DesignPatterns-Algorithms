#include "./../../../../Include/Common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 
    701. Insert into a Binary Search Tree   
    Insert the value into the BST. Return the root node of the BST after the insertion. 
    
    https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
*/



enum ParentType {
    LEFT = 0, 
    RIGHT
};

class Solution {
public:
    void insert(TreeNode *root, TreeNode *parent, ParentType type, TreeNode *tbInserted){
        if(!root) {
            if(type == RIGHT)
                parent->right = tbInserted;
            else
                parent->left = tbInserted;
        } else {
            if(root->val < tbInserted->val)
                insert(root->right, root, RIGHT, tbInserted);
            else 
                insert(root->left, root, LEFT, tbInserted);
        }
    }


    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val); 
        TreeNode *dummy = new TreeNode(0);
        dummy->right = root; 
        insert(root, dummy, RIGHT, node);   
        
        return dummy->right;       
    }
};