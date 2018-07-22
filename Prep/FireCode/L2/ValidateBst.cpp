#include "./../../../Include/Common.h"
using namespace std;


typedef struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
};


bool do_validate_bst( treeNode* root,
                      treeNode *left_ancestor = nullptr, 
                      treeNode *right_ancestor = nullptr)
{
    if(root == nullptr) {
        return true; // leaf
    }
    
    if(right_ancestor && root->value > right_ancestor->value){
           return false; 
    }
    
    if(left_ancestor && root->value < left_ancestor->value){
           return false; 
    }
    
    return do_validate_bst(root->left, left_ancestor, root) && 
           do_validate_bst(root->right, root, right_ancestor); 
}

// Add any helper functions(if needed) above.
bool validate_bst(treeNode* root)
{
    if(root == nullptr)
        return true;

    return do_validate_bst(root);
}


