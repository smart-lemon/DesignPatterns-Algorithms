#include "./../../../Include/Common.h"


struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
};


// Add any helper functions(if needed) above.
vector<int> level_order(treeNode* root)
{
    queue <treeNode*> q;
    vector<int> res; 
    if(root == nullptr)
        return res;
    
    q.push(root);
    
    while(!q.empty()){
        treeNode* node = q.front();
        q.pop();
        res.push_back(node->value);
        
        if(node->left)
            q.push(node->left);
        
        if(node->right)
            q.push(node->right);
    };
    return res; 
}