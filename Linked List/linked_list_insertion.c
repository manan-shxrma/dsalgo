#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;//node type pointer
};
struct node * insertionbeginning(struct node* head, int data){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node * insertionindex(struct node* head, int data, int index){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
    while(i!= index - 1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}
struct node * insertionend(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p  = head;
    int i = 0;
    while(p->next!=NULL){
        p = p->next;
        i++;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
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
    head = insertionbeginning(head, 32);
    head = insertionindex(head, 27, 2);
    head = insertionend(head,5);
    traversal(head);
    return 0;
}
