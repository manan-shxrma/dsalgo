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

int main()
{
    BTNode<int>* root = new BTNode<int>(1);
    BTNode<int>* n1 = new BTNode<int>(2);
    BTNode<int>* n2 = new BTNode<int>(3);
    root->left = n1;
    root->right = n2;
    delete root;
    return 0;
}