#include "./../../Include/CommonInc.h"

typedef struct AvlTree {
    AvlTree *left;
    AvlTree *right; 
    int data; 
    int height;
};


/*
    Left Left case

    Inserted into the left subtree of the left child of the violated node (X)
    
    e.g 5 is violated,  

            10                                         10 
           /  \                                       /  \
          5   15          Right Rotate at -10       -10  15
         /                       ->                 /  \
       -10                                        -20   5
       /
    -20  <- Newly added
*/ 



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