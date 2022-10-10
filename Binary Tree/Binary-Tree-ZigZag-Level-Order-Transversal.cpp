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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
        if(!root)return{};
        queue<TreeNode* > q;
        q.push(root);
        bool check = false;
        while(!q.empty()){
           
            int size = q.size();
            vector<int> level(size);
            for(int i =0 ; i< size ; i++){
                TreeNode* node = q.front();
                q.pop();
                int index ;
                if(check){
                     index = size-i-1;
                }else{
                    index = i;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                level[index] = node->val;
            }
            ans.push_back(level);
            check = !check;
        }
        return ans;
    }
}
