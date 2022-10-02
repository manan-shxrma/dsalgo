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

Node* midNode(Node *head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast){
        return slow->next; //even
    }
    return slow; //odd
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
    head = midNode(head);
    cout<<head->data<<endl;
    return 0;
}