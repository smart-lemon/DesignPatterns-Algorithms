#include "./../../../Include/Common.h"
#include <iostream>
#include <vector>
using namespace std;

/*
    Preorder Traversal
   https://leetcode.com/problems/binary-tree-preorder-traversal 
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Combines two vectors
vector<int>& concatenate(vector<int> & a, vector<int> & b){
    // Add b to the end of  
    a.insert( a.end(), b.begin(), b.end());
    return a; 
}

class Solution {
public:
    
   
    
    vector<int> preorderTraversal(TreeNode* root) {
        // Output
        vector<int> out;

        if(root == nullptr) {
            return out;
        }
        vector<int> left, right;
        
        // Middle 
        out.push_back(root->val);
        
        // Left 
        left = preorderTraversal(root->left);
        if(left.size() > 0)
            out = concatenate(out, left);

        // Right 
        right = preorderTraversal(root->right);
        if(right.size() > 0)
            out = concatenate(out, right);

        return out;
    }
};


/*
     N-ary Preorder
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

    void preorderHelper (Node* root, vector<int>& result) {
        if (!root) {
            return ;
        }

        result.push_back(root->val);
        
        for (const auto& child : root->children) {
            preorderHelper(child, result);
        }
    }
};