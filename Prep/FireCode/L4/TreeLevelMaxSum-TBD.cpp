

struct treeNode{
    int value;              /* value of the node */
    struct treeNode *left;  /* pointer to the left child node */
    struct treeNode *right; /* pointer to the right child node */
};


/* 
    Given a binary tree, write a method to return the level that has the maximum sum
          1
         / \
        2   3     
       / \ / \  
      4  5 6  7
     /
    8   
    
    Output :  2 
*/
int find_max_sum_level(treeNode* root){
    queue <treeNode*> q;
    if(root == nullptr)
        return -1;
    
    q.push(root);
    q.push(nullptr);
    
    int max_sum = 0;
    int sum = 0;
    while(!q.empty()){
        treeNode* node = q.front();
        q.pop();
        if(node == nullptr){
            if(max_sum > sum)
                max_sum = sum;
            sum = 0;
            q.push(nullptr);

        } else {
            sum += node->value;
        }
        
        if(node->left)
            q.push(node->left);
        
        if(node->right)
            q.push(node->right);
    };
    return max_sum;     
}