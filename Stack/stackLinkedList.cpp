#include<iostream>
using namespace std;
template<typename T>
// Node class for implementing Linked List.
class Node{

public:

T data;
Node<T>*nextNode;
Node<T>*prevNode;

Node(T data){
    this->data=data;
    nextNode=NULL;
    prevNode==NULL;
}
Node(){
    nextNode=NULL;
    prevNode==NULL;
}

};
// Stack class for Implementing Stack using Linked List.

template<typename T>
class Stack{
    private:
    Node<T>*head;
    int count;

    public:
    Stack(){
        head=NULL;
        count=0;
    }

    void push(T element){
        Node<T>*newNode=new Node<T>(element);
        newNode->prevNode=head;
        head=newNode;
        count++;
    }
    int size(){
        return count;
    }

    bool isEmpty(){
        return count==0;
    }

    T pop(){
        if(count==0){
            cout<<"Empty stack"<<endl;
            return 0;
        }
        else{
            Node<T>*temp=head;
            T data=temp->data;
            head=head->prevNode;
            delete temp;
            count--;
            return data;
        }
    }

    T top(){
        if(count==0){
            cout<<"Empty stack"<<endl;
            return 0;
        }
        return head->data;
    }


};
