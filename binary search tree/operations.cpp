#include<bits/stdc++.h>
using namespace std;
struct node {
   int data;   
   node* leftChild;
   node* rightChild;
};

node* GetNewNode(int data) //to store the address the root node
{
    node* newnode = new node();
    newnode->data = data ;
    newnode->leftChild = newnode->rightChild =  NULL;
    return newnode;

}
void Insert(node* root,int data)
{
    if(root == NULL)//empty tree
    {
        root = GetNewNode(data);
    }
    else if(data<= root->data)
    {
        root->leftChild = GetNewNode(data);
    }
    else{
        root->rightChild = GetNewNode(data);
    }
    
    return;
    
}

bool Search(node* root,int data)
{
    if(root == NULL)
        return false;
    if(root->data == data)
        return true;
    else if (data <= root->data) return Search(root->leftChild,data);
    else return Search(root->rightChild,data);
}
int main(){
    node* root; //pointer to root node
    root = NULL; //initially tree is empty
    int x;
    cout<<"Enter the integer you want to insert : ";
    cin>>x;
    root=GetNewNode(x);

    int add;
    cout<<"Enter 1 if you want to insert more elements, otherwise 0 : ";
    cin>>add;
    if(add==1)
    {
        cout<<"Enter the integer you want to insert : ";
        cin>>x;
        Insert(root,x);
        while(true){ 
            int i;
            cout<<"Enter 1 if you want to insert more elements, otherwise 0 : ";
            cin>>i;
            if(i==0) break;
            int x;
            cout<<"Enter the integer you want to insert : ";
            cin>>x;
            Insert(root,x);
        }
    }
    else{
        cout<<"Hope you have inserted all the elements that you want to insert. Let's move further now!"<<endl;
    }
    int number;
    cout<<"Enter the number you want to search\n";
    cin>>number;
    if(Search(root,number)){
        cout<<"this number is present\n";
    }
    else if(Search(root->leftChild,number))
    {
        cout<<"this number is present\n";
    }
    else if(Search(root->rightChild,number))
    {
        cout<<"this number is present\n";
    }
    else{
        cout<<"Not found\n";
    }
    return 0;

}
