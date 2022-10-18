// Clone linked list with random pointer
class Node{
  int data;
  Node* next;
  Node(int val){
    data=val;
    next=NULL;
  }
}
void insertAtTail(Node* &head,Node* &tail,int d){
        Node* temp=new Node(d);
        if(head==NULL){
            head=temp;
            tail=temp;
            return ;
        }
        tail->next=temp;
        tail=temp;
    }
    
 Node *copyList(Node *head)
 {
        
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;
            
            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }
        
        temp=head;
        
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->arb!=NULL){
            
                    temp->next->arb=temp->arb->next;
                }
                else{
                    temp->next->arb=temp->arb;
                }
            }
            temp=temp->next->next;
        }
        
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            
            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
            
        }
        return cloneHead;
        
 }
