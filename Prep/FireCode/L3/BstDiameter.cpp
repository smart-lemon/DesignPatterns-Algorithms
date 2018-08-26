struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
};

static int max(int a, int b) { return (a > b)? a : b; }

// Not used in this program 
int find_depth(treeNode *node){
    if(node == nullptr){
        return 0; 
    }
    
    return max(find_depth(node->right), find_depth(node->left)) + 1;
}

// A longest path or route between any two nodes in a tree. 
// The path may or may not go through the root.
int diameterOpt(treeNode *root, int *height) {
    
    if(root == nullptr) {
        *height = 0;
        return 0;
    }
    int left_ht  = 0; 
    int right_ht = 0;
    
    int left_dia  = diameterOpt(root->left,  &left_ht);
    int right_dia = diameterOpt(root->right, &right_ht);
    
    // Height or depth is the max of the left or right subtree depth + 1
    *height = max(left_ht, right_ht) + 1;

    return max(left_ht + right_ht + 1, max(left_dia, right_dia));
}

int diameter(treeNode* root)
{
    int height = 0; 
    return diameterOpt(root, &height);
}