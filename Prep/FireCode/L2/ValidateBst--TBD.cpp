#include "./../../../Include/Common.h"
using namespace std;


typedef struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
};


bool validate_bst(treeNode* root)
{
    if(root->left == nullptr && root->right == nullptr) {
        return true; // leaf
    }
    
    bool left_val = true, right_val = true; 
    if(root->left){
        if(root->value > root->left->value) {
            left_val = validate_bst(root->left);
        } else {
            return false; 
        }
    }
    
     if(root->right){
        if(root->value <= root->right->value) {
            right_val = validate_bst(root->right);
        } else {
            return false; 
        }
    }
    
    if(left_val && right_val)
        return true;
    return false; 
}