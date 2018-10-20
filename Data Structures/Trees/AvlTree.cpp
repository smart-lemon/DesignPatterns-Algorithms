#include "./../../Include/CommonInc.h"

typedef struct AvlNode {
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
    Left Right case

    Inserted into the right subtree of the left child of the violated node (X)
    
    e.g 5 is violated,  

            10                                         10                                  10 
           /  \                                       /  \                                /  \
          5   15        Left Rotate at -10           5   15      Right Rotate at -5     -5   15 
         /                       ->                 /                  ->               /  \
       -10                                        -5                                  -10   5
          \                                       /
          -5    <- Newly added                  -10
*/ 



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





int testAvl() 
{
   
   return 0;
}