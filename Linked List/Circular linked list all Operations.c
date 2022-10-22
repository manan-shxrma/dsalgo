#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head,*temp,*temp1,*newnode;
struct node * insert_at_beg(struct node *);
struct node * insert_at_end(struct node *);
struct node * delete_at_beg(struct node *);
struct node * delete_at_end(struct node *);
int count_nodes(struct node*);
struct node* sort(struct node*);
void display(struct node *);


main()
{
  head=NULL;
  int ch,c;
  while(1)
  {
printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n\n");
  printf("1) insert at begining\n");
  printf("2) insert at end\n");
  printf("3) delete at begining\n");
  printf("4) delete at end\n");
  printf("5) display\n");
  printf("6) count nodes\n");
     printf("7) sort nodes\n");
     printf("8) exit\n");
     printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");

  printf("\n-> Enter the choice: ");
scanf("%d",&ch);
switch(ch)
{
  case 1: newnode=(struct node *)malloc(sizeof(struct node));
                 printf("\nEnter the data: ");
                 scanf("%d",&newnode->data);
                 head=insert_at_beg(newnode);
                 break;
  case 2: newnode=(struct node *)malloc(sizeof(struct node));
                 printf("\nEnter the data:");
                 scanf("%d",&newnode->data);
                 head=insert_at_end(newnode);
                 break;
case 3: head=delete_at_beg(head);
               break;
case 4:head=delete_at_end(head);
               break;
case 5: display(head);
              break;
case 6: c=count_nodes(head);
                            printf("\nNo of nodes=%d\n",c);
                            break;
case 7: head=sort(head);
        printf("\nThe Sorted List is:\n");
        display(head);
                             break;
            case 8: exit(0);break;
default:printf("\nInvalid choice\n");break;
}
}
}


struct node * insert_at_beg(struct node *newnode)
{
   if(head==NULL)
     {
        head=newnode;
        newnode->next=head;
     }
     else
     {
        temp=head;
        while(temp->next!=head)
        {
           temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
     }
     return(head);
}


struct node * insert_at_end(struct node *newnode)
{
   if(head==NULL)
     {
        head=newnode;
        newnode->next=head;
     }
     else
     {
        temp=head;
        while(temp->next!=head)
        {
           temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
     }
     return(head);
}



struct node * delete_at_beg(struct node *head)
{
   if(head==NULL)
     {
        printf("CLL is empty--cant delete\n");
     }
     else
     {
         if(head->next==head)
         {
            printf("node deleted=%d\n",head->data);
            free(head);
            head=NULL;
         }
         else
         {
             temp=head;
             while(temp->next!=head)
             {
               temp=temp->next;
             }
              printf("node deleted=%d\n",head->data);
              temp1=head->next;
              free(head);
              temp->next=temp1;
              head=temp1;
         }
     }
     return(head);
}



struct node * delete_at_end(struct node *head)
{
   if(head==NULL)
     {
        printf("CLL is empty--cant delete\n");
     }
     else
     {
         if(head->next==head)
         {
            printf("node deleted=%d\n",head->data);
            free(head);
            head=NULL;
         }
         else
         {
             temp=head;
             while(temp->next!=head)
             {
             temp1=temp;
               temp=temp->next;
             }
              printf("node deleted=%d\n",temp->data);
             free(temp);
             temp1->next=head;
         }
     }
     return(head);
}



void display(struct node *head)
{
  if(head==NULL)
     {
        printf("CLL is empty\n");
     }
     else
     {
         temp=head;
         while(temp->next!=head)
         {
            printf("%d->",temp->data);
            temp=temp->next;
         }
         printf("%d->\n",temp->data);
     }
}

int count_nodes(struct node *head)
{
    int c=0;
    if(head==NULL)
   return(c);
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            c++;
            temp=temp->next;
        }
        return(c+1);
    }
}

struct node* sort(struct node* head)
{
    int c,i,j;
  if(head==NULL)
    printf("CLL is empty--cant sort\n");
  else
  {
      if(head->next==head)
        return(head);
      else
      {
          temp1=(struct node*)malloc(sizeof(struct node));
          c=count_nodes(head);
          for(i=1;i<c;i++)
          {
               temp=head;
                for(j=1;j<=c-i;j++) { if(temp->data > temp->next->data)
                    {
                        temp1->data=temp->data;
                        temp->data=temp->next->data;
                        temp->next->data=temp1->data;
                    }
                    temp=temp->next;
                }
          }
      }
  }
  return(head);
}



/*Printing,,,

+++++++++++++++++++++++++++++++++++++++++++++

1) insert at begining
2) insert at end
3) delete at begining
4) delete at end
5) display
6) count nodes
7) sort nodes
8) exit

+++++++++++++++++++++++++++++++++++++++++++++

-> Enter the choice: 1

Enter the data: 10

+++++++++++++++++++++++++++++++++++++++++++++

1) insert at begining
2) insert at end
3) delete at begining
4) delete at end
5) display
6) count nodes
7) sort nodes
8) exit

+++++++++++++++++++++++++++++++++++++++++++++

-> Enter the choice: 1

Enter the data: 60

+++++++++++++++++++++++++++++++++++++++++++++

1) insert at begining
2) insert at end
3) delete at begining
4) delete at end
5) display
6) count nodes
7) sort nodes
8) exit
