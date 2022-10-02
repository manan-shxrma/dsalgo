#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

bool searchLL(Node *head, int target){
    if(head==NULL){
        return false;
    }
    if(head->data==target){
        return true;
    }
    return searchLL(head->next, target);
}

Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1){
        Node *n = new Node(data);
        if(head==NULL){
        head = n;
        tail = n;
        }
        tail->next = n;
        tail = n;
        cin>>data;
    }
    return head;
}


int main()
{
    Node *head = takeInput();
    int target;
    cin>>target;
    print(head);
    cout<<endl;
    if(searchLL(head, target)){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
    return 0;
}