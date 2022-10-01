// In inorder traversal of binary tree, we traverse through tree recursively by visiting in the order: left -->  right -->  root

void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        inorder(root->left, ans);  // left->val
        inorder(root->right, ans); // right->val
        ans.push_back(root->val);  // root->val
}
    
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
}