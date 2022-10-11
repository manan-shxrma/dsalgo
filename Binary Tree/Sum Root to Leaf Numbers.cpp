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
    int sum =0;
    void dfs(TreeNode* root, int num){
     if(root == nullptr){
      return;
  }
      num =num*10+root->val;
      if(root->left== nullptr && root->right == nullptr){
       sum+=num;
       return;
 
}
      dfs(root->left,num);
      dfs(root->right,num);



}
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};
