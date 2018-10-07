#include "./../../../../Include/Common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> hashmap;

        vector<TreeNode*> result;

        serialize(root, hashmap);
        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
            if (it->second.size() > 1) result.push_back(it->second[0]);
        return result;
    }
private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& hashmap) {
        if (!node) 
            return "";

        string s = "(" + serialize(node->left, hashmap) 
                   + to_string(node->val) 
                   + serialize(node->right, hashmap) + ")";
        hashmap[s].push_back(node);
        return s;
    }
};