// To remove duplicates from the  unsorted linked list
Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     if(head==NULL || head->next==NULL){
         return head;
     }
     
     Node* curr=head;
     Node* prev=NULL;
     unordered_map<int,bool> visited;
     while(curr!=NULL){
         if(!visited[curr->data]){
             visited[curr->data]=1;
             prev=curr;
             curr=curr->next;
         }
         else{
             Node* toDel=curr;
             prev->next=curr->next;
             curr=curr->next;
             delete toDel;
         }
     }
     return head;
     
     
    }
