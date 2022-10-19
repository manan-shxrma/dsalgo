#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
int isempty(struct node * top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
int isfull(struct node * head){
    struct node * p = (struct noode*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    return 0;
}
struct node *  push(struct node * top, int x){
    if(isfull(top)){
        printf("STACK OVERFLOW : \n");
    }
    else{
        struct node * n = (struct node * )malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct node ** top){
    if(isempty(*top)){
        printf("stack under flow : ");
    }
    else{
        struct node * n = *top;
        *top =  (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
};
void traversal(struct node * ptr  ){
    while(ptr!=NULL){
        printf("element  : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int peek(struct node * top, int index){
    struct node * ptr = top;
    for(int i = 0;(i<(index-1)&&ptr!=NULL);i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
};
int main(){
    struct node*top =  NULL;
    top = push(top, 78);
    top = push(top, 21);
    top = push(top, 35);
    top = push(top, 4);
    traversal(top);
    int element  = pop(&top);
    printf("\npopped element is %d\n", element);
    traversal(top);
    for(int i = 1;i<=3;i++){
        printf("VALUE AT POSITITON %d IS :  %d\n", i, peek(top, i));
    }
    return 0;
}
