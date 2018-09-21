#include "./../../../Include/Common.h"

struct treeNode{
    int value;              /* value of the node */
    struct treeNode *left;  /* pointer to the left child node */
    struct treeNode *right; /* pointer to the right child node */
};

// ----------------------------------

class BstIterator {
    stack<treeNode *> treeStack; 

    public:
    BstIterator(treeNode *root) {
       updateStack(root);
    }

    void updateStack(treeNode *node) {
        while(node) {
            treeStack.push(node);
            node = node->left;
        }
    }

    bool hasNext(){
        return !treeStack.empty();
    }

    treeNode *next() {
        treeNode *node = nullptr;
        if(hasNext()) {
            node = treeStack.top(); 
            treeStack.pop();
            if(node->right) {
                updateStack(node->right);
            }
        }
        return node;
    }
};

bool validate_bst_itr(treeNode* root) {
    BstIterator iterator(root);
    int prev = INT_MIN;
    int curr;
    while(iterator.hasNext()){
        treeNode *node = iterator.next(); 
        curr = node->value;
        if(curr < prev)
            return false;
        prev = curr;
    }
    return true;
}