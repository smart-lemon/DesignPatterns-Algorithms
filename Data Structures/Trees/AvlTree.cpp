#include "./../../Include/CommonInc.h"

class AvlNode {
    
    public:
        AvlNode *left;
        AvlNode *right; 
        int data; 
        int height;
};

int getHeight(AvlNode *node) {
    if(!node) {
        return 0;
    } else {
        node->height;
    }
}


int getBalance(AvlNode * root){
    if (root == nullptr) 
        return 0; 
    return getHeight(root->left) - getHeight(root->right);
}


AvlNode* newNode(int key) 
{ 
    AvlNode* node = new AvlNode; 
    node->data   = key; 
    node->left   = nullptr; 
    node->right  = nullptr; 
    node->height = 1;  // new node is initially added at leaf 

    return(node); 
} 


/*
    Left Left case

    Inserted into the left subtree of the left child of the violated node (X)
    
    e.g 20 is violated,  

             /                                           /
            20                                          15 
           /  \                                       /    \
          15   25          Right Rotate at 20        10     20
         /  \                      ->               /  \   /  \
        10  18                                    -10   5 18  25
       /
    -10  <- Newly added

    Generically : T1, T2, T3 and T4 are subtrees.
           y                                      x 
          / \                                   /   \
         x   T4      Right Rotate (z)          z      y
        / \          - - - - - - - - ->      /  \    /  \ 
       z   T3                               T1  T2  T3  T4
      / \
    T1   T2

*/ 


struct AvlNode *singleRotateRight(AvlNode *y) 
{ 
    AvlNode *x = y->left; 
    AvlNode *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; 
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 
  
    // Return new root 
    return x; 
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

       x                               y
     /  \                            /   \ 
    T1   y     Left Rotate(x)       x      z
        /  \   - - - - - - - ->    / \    / \
       T2   z                     T1  T2 T3  T4
           / \
          T3  T4

*/ 



AvlNode *singleRotateLeft(AvlNode *x) 
{ 
    AvlNode *y = x->right; 
    AvlNode *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; 
  
    // Return new root 
    return y; 
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
    Z->left = singleRotateLeft(Z->left);

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
    Z->right = singleRotateRight(Z->left);
    return singleRotateLeft(Z);
}

AvlNode* avlInsert(AvlNode* node, int key) { 
    /* 1.  Perform the normal BST insertion */
    if (node == nullptr) 
        return(newNode(key)); 
  
    if (key < node->data) 
        node->left  = avlInsert(node->left, key); 
    else if (key > node->data) 
        node->right = avlInsert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(getHeight(node->left), 
                           getHeight(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced 
    */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->data) 
        return singleRotateRight(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->data) 
        return singleRotateLeft(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->data) 
    { 
        node->left =  singleRotateLeft(node->left); 
        return singleRotateRight(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->data) 
    { 
        node->right = singleRotateRight(node->right); 
        return singleRotateLeft(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
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


void preOrder(AvlNode *root) 
{ 
    if(root != nullptr) 
    { 
        cout <<  root->data << " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
  


int testAvl() {
    AvlNode *root = nullptr;

    root = avlInsert(root, 10); preOrder(root);
    cout << endl;
    root = avlInsert(root, 20);  preOrder(root);
    cout << endl;
    root = avlInsert(root, 30);  preOrder(root);
    cout << endl;
    root = avlInsert(root, 40);  preOrder(root);
    cout << endl;
    root = avlInsert(root, 50);  preOrder(root);
    cout << endl;
    root = avlInsert(root, 25);  preOrder(root);
    cout << endl;

  /* 
    The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 


    Preorder 30 20 10 25 40 50 

  */

    return 0;
}