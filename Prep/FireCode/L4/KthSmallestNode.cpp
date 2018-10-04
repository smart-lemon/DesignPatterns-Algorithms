struct treeNode{
    int value;              /* value of the node */
    struct treeNode *left;  /* pointer to the left child node */
    struct treeNode *right; /* pointer to the right child node */
};

static treeNode *kthSmolest = nullptr; 

void kthSmallestUtil(treeNode* root, const int k, int &c) {
    if(root == nullptr)
        return;
    kthSmallestUtil(root->left, k, c);

    c++;
    if(c == k){
        kthSmolest = root;
        return;
    }

    kthSmallestUtil(root->right, k, c);
}


treeNode* find_kth_smallest(treeNode* root, int k){
    int c = 0;
    kthSmolest = nullptr; 
    kthSmallestUtil(root, k, c);
    return kthSmolest;
}