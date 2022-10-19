#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;//node type pointer
};
struct node * insertion_beginning(struct node * head, int data ){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    struct node * p = head->next;
    ptr->data = data;
    while(p->next !=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return ptr;
};
struct node * insertion_index(struct node * head, int data , int index){
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

};
void traversal(struct node * head  ){
    struct node * ptr = head;
    do{
        printf("Element is : %d\n",  ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
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
