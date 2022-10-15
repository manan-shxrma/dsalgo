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


Node* surviver(Node *head, int k){
    Node *temp = head;
    temp = temp->next;
    while(temp && temp->next){
        Node* n = temp->next;
        temp->next = temp->next->next;
        n->next = NULL;
        delete n;
        temp = temp->next;
    }
    
    return temp;
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
    int k;
    cin>>k;
    head = surviver(head,k);
    print(head);
    return 0;
}