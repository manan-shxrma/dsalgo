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
    int maxLevelSum(TreeNode* root) {
        int maxSum =INT_MIN;
        int count =0;
        queue<TreeNode* > q;
        q.push(root);
        int level =0;
        while(!q.empty()){
            int size = q.size();
            int levelSum =0;
            for(int i =0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                levelSum+= node->val;
            }
            level++;
            if(maxSum<levelSum){
                maxSum = levelSum;
                count = level;
            }
        }
        return count;
        
    }
};
