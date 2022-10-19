#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;//node type pointer
};
struct node * deletion_1st_node(struct node * head){
    struct node * ptr = head;
    head  = head->next;
    free(ptr);
    return head;
};
struct node * deletion_index(struct node * head, int index){
    struct node * p = head;
    int i = 0;
    struct node * q = head->next;
    for(int i = 0;i<index - 1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};
struct node * deletion_end(struct node * head){
    struct node * p = head;
    struct node * q = p->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;

};
struct node * deletion_value(struct node * head, int value){
    struct node * p = head;
    int i = 0;
    struct node * q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
       p->next = q->next;
       free(q);
    }
    return head;
};
void traversal(struct node * ptr  ){
    while(ptr!=NULL){
        printf("element  : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct node * head ;
    struct node * secondnode;
    head  = (struct node * )malloc(sizeof(struct node));
    secondnode = (struct node * )malloc(sizeof(struct node));
    head->data = 9;//storing data
    head->next = secondnode;//storing the next node data adress
    secondnode->data = 11;//storing data
    secondnode->next = NULL;//storing the next node data adress
    traversal(head);
    printf("\nAfter insertion\n\n");
    head = deletion_1st_node(head, 32);
    head = deletion_index(head, 27, 2);
    head = deletion_value(head,5);
    traversal(head);
    return 0;
}
