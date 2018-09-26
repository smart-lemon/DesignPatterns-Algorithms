/*
    230. Kth Smallest Element in a BST
    https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int kthSmallestAns = 0;

    void kthSmallestUtil(TreeNode* root, const int k, int &c) {
        if(root == nullptr)
            return;
        kthSmallestUtil(root->left, k, c);

        c++;
        if(c == k){
            kthSmallestAns = root->val;
            return;
        }

        kthSmallestUtil(root->right, k, c);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        kthSmallestAns = 0; 
        kthSmallestUtil(root, k, c);
        return kthSmallestAns;
    }
};