#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char * arr;
};
int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }


}
int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }

}

void push(struct stack * ptr, char value){

    if(isFull(ptr)){
        printf("Stack overflow \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]  = value;
    }
}
char pop(struct stack * ptr){

    if(isEmpty(ptr)){
        printf("Stack underflow \n");
    }
    else{

        char val = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        return val;

    }
}
int paranthesis_match(char * exp){
    struct stack * sp = (struct stack * )malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));//this is character stack
    for(int i = 0; i<exp[i]!=0;i++){
        if(exp[i]=='('){
                push(sp, '(');//inserting the element is inserted in stack
           }
        else if(exp[i]==')'){//exp is the input expression
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }

}
int main(){
    char * exp  = "8*(7)";
    if(paranthesis_match(exp)){
        printf("THE PARANTHESIS IS MATCHING ");
    }
    else{
        printf("THE PARANTHESIS IS NOT MATCHING ");
    }

    return 0;
}
