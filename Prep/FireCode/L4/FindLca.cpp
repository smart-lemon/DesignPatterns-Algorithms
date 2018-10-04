struct treeNode{
    int value;              /* value of the node */
    struct treeNode *left;  /* pointer to the left child node */
    struct treeNode *right; /* pointer to the right child node */
};

/*
    Given a binary tree and the data values of two tree nodes, implement a function to find and return the
    LCA (Lowest Common Ancestor) node of the two nodes.
*/


treeNode *recursiveLca(treeNode* root, int a, int b){
    if(root == nullptr)
        return nullptr;
    
    treeNode *leftFound = recursiveLca(root->left, a, b);
    treeNode *rightFound = recursiveLca(root->right, a, b);
    
    if(leftFound && rightFound)
        return root;
    
    if(root->value == a || root->value == b)
        return root;
    
    return leftFound? leftFound : rightFound; 
}

// Add any helper functions(if needed) above.
treeNode* find_lca(treeNode* root, int a, int b){
    
    return recursiveLca(root, a, b);
}