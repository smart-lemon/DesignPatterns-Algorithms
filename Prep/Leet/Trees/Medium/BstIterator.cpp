#include "./../../../../Include/Common.h"

/*
    173. Binary Search Tree Iterator
    Implement an iterator over a binary search tree (BST). 
    Calling next() will return the next smallest number in the BST 

    https://leetcode.com/problems/binary-search-tree-iterator
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
    Runtime analysis : 
    next() and hasNext() : run in average O(1) time and uses O(h) memory, 
    where h is the height of the tree.
*/

class BSTIterator {
    stack<TreeNode *> stk;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *node = root;

        while(node) {
            stk.push(node);
            node = node->left;
        } 
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *least = stk.top();
        int smallest = least->val;
        stk.pop();

        if(least->right) {
            TreeNode *node = least->right;
            while(node) {
                stk.push(node);
                node = node->left;
            } 
        }
        return smallest;
    }
};

/*
   Your BSTIterator will be called like this:
   BSTIterator i = BSTIterator(root);
   while (i.hasNext()) cout << i.next();
*/