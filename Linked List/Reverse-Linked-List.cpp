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


Node* reverse(Node *head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        Node* n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
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
    print(head);
    cout<<endl;
    head = reverse(head);
    print(head);
    return 0;
}