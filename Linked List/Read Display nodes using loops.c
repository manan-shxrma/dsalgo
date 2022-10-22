#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;
struct node* insert_at_end(struct node *);
void display(struct node *);
struct node *temp,*temp1,*newnode;
main()
{
int ch,p=0,n;
head=NULL;

printf("\nEnter the Number of Nodes you want!: ");
scanf("%d",&n);

             printf("\nEnter the Datails of Nodes:\n");
             while(p!=n)
             {
             newnode=(struct node*)malloc(sizeof(struct node));
             scanf("%d",&newnode->data);
             head=insert_at_end(newnode);
             p++;
             }
printf("\nThe nodes data You have entered are:\n");
display(head);
}
struct node* insert_at_end(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;

     }
     temp->next=newnode;
        newnode->next=NULL;
        return(head);

   }
}
void display(struct node *head)
{
   if(head==NULL)
   {
     printf("The linked list is empty\n");
   }
   else
   {
      temp=head;
      while(temp!=NULL)
      {
         printf("%d->",temp->data);
         temp=temp->next;
      }
      printf("\n");
   }
}


/*OutPut:

Enter the Number of Nodes you want!: 5

Enter the Datails of Nodes:
6
3
2
1
3

The nodes data You have entered are:
6->3->2->1->3->
