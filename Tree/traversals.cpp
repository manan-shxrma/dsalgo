#include<bits/stdc++.h>
using namespace std;

class Tree
{
    
    public:
    int data;
    Tree *left,*right;
    Tree(int val)
    {
        data=val;
        left=right=NULL;
    }
    void inorder(Tree *root);
    void preorder(Tree* root);
    void postorder(Tree* root);
    void leftView(Tree* root,int depth,int &maxDepth);
    void rightView(Tree* root,int depth,int &maxDepth);
};

void Tree::leftView(Tree* root,int depth,int &maxDepth)
{
    if(!root)   return;
    if(depth>maxDepth)
    {
        cout<<root->data<<" ";
        maxDepth=depth;
    }
    leftView(root->left,depth+1,maxDepth);
    leftView(root->right,depth+1,maxDepth);
}

void Tree::rightView(Tree* root,int depth,int &maxDepth)
{
    if(!root)   return;
    if(depth>maxDepth)
    {
        cout<<root->data<<" ";
        maxDepth=depth;
    }
    rightView(root->right,depth+1,maxDepth);
    rightView(root->left,depth+1,maxDepth);
}

void Tree:: inorder(Tree* root)
{
    if(!root)   return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void Tree:: preorder(Tree* root)
{
    if(!root)   return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void Tree:: postorder(Tree* root)
{
    if(!root)   return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7

    Tree *root=new Tree(1);
    root->left=new Tree(2);
    root->right=new Tree(3);
    root->left->left=new Tree(4);
    root->left->right=new Tree(5);
    root->right->left=new Tree(6);
    root->right->right=new Tree(7);

    cout<<"Inorder:\t";
    root->inorder(root);
    cout<<endl<<"Preorder:\t";
    root->preorder(root);
    cout<<endl<<"Postorder:\t";
    root->postorder(root);
    cout<<"\nLeft View:\t";
    int maxDepth=-1;
    root->leftView(root,0,maxDepth);
    cout<<"\nRight View:\t";
    maxDepth=-1;
    root->rightView(root,0,maxDepth);
}


