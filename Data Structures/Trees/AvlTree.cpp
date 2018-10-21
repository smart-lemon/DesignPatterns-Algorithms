#include "./../../Include/CommonInc.h"

class AvlNode {
    
    public:
        AvlNode *left;
        AvlNode *right; 
        int data; 
        int height;
};

int getHeight(AvlTree *node) {
    if(!node) {
        return -1;
    } else {
        node->height;
    }
}

/*
    Left Left case

    Inserted into the left subtree of the left child of the violated node (X)
    
    e.g 20 is violated,  

             /                                           /
            20                                          15 
           /  \                                       /    \
          15   25          Right Rotate at 15        10     20
         /  \                      ->               /  \   /  \
        10  18                                    -10   5 18  25
       /
    -10  <- Newly added
*/ 


AvlNode *singleRotateRight(AvlNode *X) {
    AvlNode *newX = X->left;
    X->left = newX->right;
    newX->right = X;

    // Reconfigure the heights (first X then newX)    
    X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
    newX->height = max(getHeight(newX->left), getHeight(X)) + 1;
    return newX;
}



/*
    Right Right case

    Inserted into the right subtree of the right child of the violated node (X)
    
    e.g 20 is violated,  

            10                                         10 
           /  \                                       /  \
          5   20          Left Rotate at 30          5   30
                \                 ->                     / \
                30                                      20  40
                  \
                  40    <- Newly added
*/ 




AvlNode *singleRotateLeft(AvlNode *X) {
    AvlNode *newX = X->right;
    X->right = newX->left;
    newX->left = X;

    // Reconfigure the heights (first X then newX)    
    X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
    newX->height = max(getHeight(newX->right), getHeight(X)) + 1;
    return newX;
}

/*
    Left Right case

    Inserted into the right subtree of the left child of the violated node (Z)
    
    e.g 5 is violated,  

            10                                         10                                  10 
           /  \                                       /  \                                /  \
          5   15        Left Rotate at -10           5   15      Right Rotate at -5     -5   15 
         /                       ->                 /                  ->               /  \
       -10                                        -5                                  -10   5
          \                                       /
          -5    <- Newly added                  -10
*/ 

AvlNode *doubleRotateLeftThenRight(AvlNode *Z) {
    Z->left = singleRotateLeft(Z->left)

    return singleRotateRight(Z);
}

/*
    Left Right case

    Inserted into the left subtree of the right child of the violated node (X)
    
    e.g 20 is violated,  

            10                                         10                                  10 
           /  \                                       /  \                                /  \
          5   20        Right Rotate at 40           5   20      Right Rotate at 30      5    30 
                \               ->                         \             ->                  /  \
                40                                         30                              20    40
               /                                             \  
              30      <- Newly added                          40
*/ 


AvlNode *doubleRotateRightThenLeft(AvlNode *Z) {
    Z->right = singleRotateRight(Z->left)

    return singleRotateLeft(Z);
}


AvlNode *avlInsert(AvlNode *root, int data){
    if(!root) {
        root = new AvlNode;
        root->left = root->right = nullptr;
        root->data = data; 
        root->height = 0;
    } else {
        if(data < root->data) {
            root->left = avlInsert(root->left, data);

            // Inserted in the left subtree. Check for imbalance
            if(getHeight(root->left) - getHeight(root->right) == 2){
                if(data < root->left->data)
                    root = singleRotateRight(root);
                else 
                    root = doubleRotateLeftThenRight(root);
            }
        } else if(data > root->data){
            root->right = avlInsert(root->right, data);
            
            // Inserted in the right subtree. Check for imbalance
            if(getHeight(root->right) - getHeight(root->left) == 2){
                if(data > root->right->data)
                    root = singleRotateLeft(root);
                else 
                    root = doubleRotateRightThenLeft(root);
            }
        }
        // Else the number is already on the tree. Now update the root's height 
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    return root;
}

void printAvlTree(AvlNode *root, int level) {
    if(root == nullptr)
         return;

    printAvlTree(root->right, level + 1);

     if(level != 0){
        for(int i = 0;i < level - 1; i++)
           cout << "|\t";
           cout <<  "|-------"  << root->data << endl;
    } else {
        cout << root->data;
    }
    printAvlTree(root->left, level + 1);

}

int testAvl() 
{
    AvlNode *root = avlInsert(nullptr, 20);

    root = avlInsert(root, 15);
    printAvlTree(root, 0);

    root = avlInsert(root, 25);    
    printAvlTree(root, 0);

    root = avlInsert(root, 10);    
    printAvlTree(root, 0);

    root = avlInsert(root, 18);    
    printAvlTree(root, 0);

    root = avlInsert(root, -10);    
    printAvlTree(root, 0);

    return 0;
}