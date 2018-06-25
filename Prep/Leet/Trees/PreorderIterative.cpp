#include "./../../../Include/Common.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// https://leetcode.com/problems/binary-tree-preorder-traversal 

class Solution {
public:
    
     vector<int> contatenate(vector<int> a, vector<int> b){
        vector<int> ab;
        ab.reserve( a.size() + b.size());
        ab.insert( ab.end(), a.begin(), a.end());
        ab.insert( ab.end(), b.begin(), b.end());
        return ab; 
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
    }
};