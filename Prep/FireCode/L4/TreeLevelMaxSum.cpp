

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
    
    vector<int> res; 
    int sum = 0;
    while(!q.empty()){
        treeNode* node = q.front();
        q.pop();
        if(node == nullptr){
            res.push_back(sum);
            sum = 0;
            if(q.size()) // Important. Dont add null markers if the queue is empty 
                q.push(nullptr);
            continue;
        } else {
            sum += node->value;
        }
        
        if(node && node->left)
            q.push(node->left);
        
        if(node && node->right)
            q.push(node->right);
    };

    // Detemine the max level
    int level = -1, max = 0; 
    for(int i = 0; i < res.size(); i++){
        if(max < res[i]){
            level = i;
            max = res[i];
        }
    }
    return level; 
}