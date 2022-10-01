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


int length(Node *head){
    int count = 0;
    while(head!=NULL){
        head = head->next;
        count++;
    }
    return count;
}

Node* merge2LL(Node* head1, Node* head2){
    if(head1==NULL){ return head2;}
    if(head2==NULL){ return head1;}

    Node* finalHead = NULL;

    if(head1->data < head2->data){
        finalHead = head1;
        head1 = head1->next;
    }
    else{
        finalHead = head2;
        head2 = head2->next;
    }

    Node* finalTail = finalHead;

    while(head1 && head2){
        if(head1->data <head2->data){
            finalTail->next = head1;
            head1 = head1->next;
        }
        else{
            finalTail->next = head2;
            head2 = head2->next;
        } 
        finalTail = finalTail->next;
    }

    if(head1){
        finalTail->next = head1;
    }
    else{
        finalTail->next = head2;
    }
    return finalHead;
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
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    Node* head = merge2LL(head1, head2);
    print(head);
    return 0;
}