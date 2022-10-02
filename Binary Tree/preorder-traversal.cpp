// In inorder traversal of binary tree, we traverse through tree recursively by visiting in the order: root --> left -->  right

void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        ans.push_back(root->val);  // root->val
        inorder(root->left, ans);  // left->val
        inorder(root->right, ans); // right->val
}
    
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
}