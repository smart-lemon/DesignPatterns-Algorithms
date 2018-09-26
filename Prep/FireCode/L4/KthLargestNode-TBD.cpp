#include "./../../../Include/Common.h"

struct treeNode{
    int value;              /* value of the node */
    struct treeNode *left;  /* pointer to the left child node */
    struct treeNode *right; /* pointer to the right child node */
};

static treeNode *kthLargest = nullptr; 
/*
    Reversed inorder traversal
*/
void kthLargestUtil(treeNode* root, const int k, int &c) {
    if(root == nullptr)
        return;
    kthLargestUtil(root->right, k, c);

    c++;
    if(c == k){
        kthLargest = root;
        return;
    }

    kthLargestUtil(root->left, k, c);
}

treeNode* find_kth_largest(treeNode* root, int k) {
    int c = 0;
    kthLargestUtil(root, k, c);
    return kthLargest;
}