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

class CQQueue{
    struct Node *front,*rear;
    public:
        CQQueue(){
            front = rear = NULL;
        }
        void enQueue(int data){
            Node* newNode = new Node(data);
            cout<<data<<" enqueued to queue"<<endl;
            if(rear == NULL){
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }

        int deQueue(){
            if(front == NULL){
                throw string("Underflow Exception");
            }
            int temp = front->data;
            front = front->next;
            if (front == NULL)
               rear = NULL;
            cout<<temp<<" DeQueued from Queue.\n";
            return temp;
        }
};


int main() {
    CQQueue ls;
    ls.enQueue(12);
    ls.enQueue(23);
    try
    {
      ls.deQueue();
    }catch (string error){
        cout<<error<<endl;
    }    
    ls.enQueue(54);
    try{
        ls.deQueue();
    }catch (string error){
      cout<<error<<endl;
    }    
    try{
      ls.deQueue();
    }catch (string error){
      cout<<error<<endl;
    }    
    try{
      ls.deQueue();
    }catch (string error){
      cout<<error<<endl;
    }    
}
