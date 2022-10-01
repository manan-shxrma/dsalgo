#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BTNode{
    public:
    T data;
    BTNode* left;
    BTNode* right;
    BTNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BTNode(){
        delete left;
        delete right;
    }
};

void printTreeR(BTNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printTreeR(root->left);
    printTreeR(root->right);
}

BTNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the data: "<<endl;
    cin>>rootData;
    BTNode<int>* root = new BTNode<int>(rootData);
    queue <BTNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();
        int leftChildData;
        cout<<"Enter the left child of "<<f->data<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
            BTNode<int>* child = new BTNode<int>(leftChildData);
            q.push(child);
            f->left = child;
        }
        int rightChildData;
        cout<<"Enter the right child of "<<f->data<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
            BTNode<int>* child = new BTNode<int>(rightChildData);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

bool searchKey(BTNode<int>* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    return searchKey(root->left, key) || searchKey(root->right, key);
}

int main()
{
    BTNode<int>* root = takeInput();
    // delete root;
    // printTreeR(root);
    cout<<searchKey(root, 3)<<endl;
    return 0;
}