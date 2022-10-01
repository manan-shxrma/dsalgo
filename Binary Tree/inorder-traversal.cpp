// In inorder traversal of binary tree, we traverse through tree recursively by visiting in the order: left -->  root -->  right

void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        inorder(root->left, ans);  // left->val
        ans.push_back(root->val);  // root->val
        inorder(root->right, ans); // right->val
}
    
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
}