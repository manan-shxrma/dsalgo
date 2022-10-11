/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter = 0;
// This function is the modified version of the depth of bt function
    int height(TreeNode* root ){
        // It is the base condition for the dfs transverse
        if(root == nullptr){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);  
        // This is the condition which help us decide at each node wether the diameter pass through this node or not 
        diameter = max(diameter , lh+rh);
       
        // This return the height of the node at which function is.
        return 1 + max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
        
    }
};
