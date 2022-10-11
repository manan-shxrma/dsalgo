#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

};


Node* BuildTree(){
    int val;
    cin>>val;
    if(val== -1){
        return;
    }
    Node* n = new Node(val);
    n->left = BuildTree();
    n->right = BuildTree();
    return n;
}

void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        if( temp == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
        }
    }

 return;
    }
   


}



int main(){

    Node* root = BuildTree();
    levelorder(root);
    cout<<endl;

    return 0;
}
