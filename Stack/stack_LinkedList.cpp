#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data = data;
    }
};

class CQStack{
    struct Node *head;
    int size;
    public:
        // Constructor for initializing the stack object
        CQStack(){
            head = NULL;
            size = 0;
        }

        void push(int data){
            Node* newLink = new Node(data);
            newLink->next = head; // newLink --> old first
            head = newLink; // first --> newLink
            cout<<data<<" pushed to stack"<<endl;
            size++;
        }

        int pop(){
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                return -1;
            }else{
                size--;
                int temp = head->data;
                head = head->next;
                cout<<temp<<" popped from the stack"<<endl;
                return temp;
            }
        }

        bool isEmpty(){
            return head == NULL;
        }

};


int main() {
    CQStack *theStack = new CQStack();
    int temp;
    theStack->push(12);
    theStack->push(23);
    temp = theStack->pop();
    theStack->push(54);
    temp=theStack->pop();
    temp=theStack->pop();
    temp=theStack->pop();
}
