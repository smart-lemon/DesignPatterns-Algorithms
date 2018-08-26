/**
 * Diameter of a Tree
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

static int max(int a, int b) { return (a > b)? a : b; }

class Solution {

    int diameterOpt(TreeNode *root, int *height) {

        if(root == nullptr) {
            *height = 0;
            return 0;
        }
        
        int left_ht  = 0; 
        int right_ht = 0;

        int left_dia  = diameterOpt(root->left,  &left_ht);
        int right_dia = diameterOpt(root->right, &right_ht);

        // Update the height or depth is the max of the left or right subtree depth + 1
        *height = max(left_ht, right_ht) + 1;

        return max(left_ht + right_ht, max(left_dia, right_dia));
    }

    public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int height = 0;
        return diameterOpt(root, &height);
    }
};