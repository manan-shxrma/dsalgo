// Boundary Traversal of a Binary Tree
void traverseLeft(Node* root,vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else{
            traverseLeft(root->right,ans);
        }
    }
    void traverseRight(Node* root,vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        if(root->right){
            traverseRight(root->right,ans);
        }
        else{
            traverseRight(root->left,ans);
        }
        ans.push_back(root->data);
    }
    
    void traverseLeaf(Node* root,vector<int> &ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        traverseRight(root->right,ans);
        return ans;
    }
