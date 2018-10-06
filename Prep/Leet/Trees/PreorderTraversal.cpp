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

// 
vector<int> concatenate(vector<int> & a, vector<int> & b){
    vector<int> ab;
    ab.reserve( a.size() + b.size() );
    // Add a then add b 
    ab.insert( ab.end(), a.begin(), a.end());
    ab.insert( ab.end(), b.begin(), b.end());
    return ab; 
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
        vector<int> out, res; 
        if(root == nullptr) {
            return out;
        }

        out.push_back(root->val);

        for(int i = 0; i < root->children.size(); i++){
            res = preorder(root->children[i]);
            if(res.size() > 0){
                out = concatenate(out, res);
            }
        }
        return out; 
    }
};