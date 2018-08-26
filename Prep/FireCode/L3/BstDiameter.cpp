struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
};

static int max(int a, int b) { return (a > b)? a : b; }

int find_depth(treeNode *node){
    if(node == nullptr){
        return 0; 
    }
    
    return max(find_depth(node->right), find_depth(node->left)) + 1;
}

int diameter(treeNode* root)
{
    if(root == nullptr)
        return 0; 
    return find_depth(root->left) + find_depth(root->right) + 1;    
    
}