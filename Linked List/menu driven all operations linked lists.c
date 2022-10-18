//CODE::::::::::::::::::::::::::::::
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;
struct node* insert_at_beg(struct node *);
struct node* insert_at_end(struct node *);
struct node* delete_at_beg(struct node *);
struct node* delete_at_end(struct node *);
void display(struct node *);
struct node *temp,*temp1,*newnode;
main()
{
int ch;
head=NULL;


   while(1)
   {
     printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");
     printf("1) insert at beginning\n");
     printf("2) insert at the end\n");
     printf("3) delete from beginning\n");
     printf("4) delete from the end\n");
     printf("5) display linked list\n");
     printf("6) exit\n");
     printf("+++++++++++++++++++++++++++++++++++++++++++++");

     printf("\n\n-> Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:newnode=(struct node*)malloc(sizeof(struct node));
             printf("Enter data: ");
             scanf("%d",&newnode->data);
             head=insert_at_beg(newnode);
             break;
    case 2: newnode=(struct node*)malloc(sizeof(struct node));
             printf("Enter data: ");
             scanf("%d",&newnode->data);
             head=insert_at_end(newnode);
             break;
    case 3: if(head==NULL)
             printf("The linked list is empty---cant delete\n");
             else
             {
                head=delete_at_beg(head);
             }
             break;
    case 4: if(head==NULL)
             printf("The linked list is empty---cant delete\n");
             else
             {
                head=delete_at_end(head);
             }
             break;
    case 5: display(head);break;
    case 6: exit(0);break;
    default: printf("Invalid choice\n");
     }
   }
}

struct node* insert_at_beg(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     newnode->next=head;
     head=newnode;
     return(head);
   }
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

struct node* delete_at_beg(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           head=head->next;
           printf("node deleted=%d\n",temp->data);
           free(temp);
           return(head);

       }
    }

}


struct node* delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           while(temp->next!=NULL)
           {
               temp1=temp;
               temp=temp->next;
           }
           printf("node deleted=%d\n",temp->data);
           free(temp);
           temp1->next=NULL;
           return(head);

       }
    }

}


/* OUTPUT::::::::::::

+++++++++++++++++++++++++++++++++++++++++++++
1) insert at beginning
2) insert at the end
3) delete from beginning
4) delete from the end
5) display linked list
6) exit
+++++++++++++++++++++++++++++++++++++++++++++

-> Enter your choice: 3
the linked list is empty---cant delete

+++++++++++++++++++++++++++++++++++++++++++++
1) insert at the beginning
2) insert at the end
3) delete from beginning
4) delete from the end
5) display the linked list
6) exit
+++++++++++++++++++++++++++++++++++++++++++++

-> Enter your choice: 1
Enter data: 10

+++++++++++++++++++++++++++++++++++++++++++++
1) insert at the beginning
2) insert at the end
3) delete from beginning
4) delete from the end
5) display the linked list
6) exit
+++++++++++++++++++++++++++++++++++++++++++++

-> Enter your choice: 2
Enter data: 20

+++++++++++++++++++++++++++++++++++++++++++++
1) insert at the beginning
2) insert at the end
3) delete from beginning
4) delete from the end
5) display the linked list
6) exit
+++++++++++++++++++++++++++++++++++++++++++++

-> Enter your choice: 5
10->20->

+++++++++++++++++++++++++++++++++++++++++++++
1) insert at the beginning
2) insert at the end
3) delete from beginning
4) delete from the end
5) display the linked list
6) exit
+++++++++++++++++++++++++++++++++++++++++++++

-> Enter your choice: 3
node deleted=10

+++++++++++++++++++++++++++++++++++++++++++++
1) insert at the beginning
2) insert at the end
3) delete from beginning
4) delete from the end
5) display the linked list
6) exit
+++++++++++++++++++++++++++++++++++++++++++++

-> Enter your choice: 4
node deleted=20

+++++++++++++++++++++++++++++++++++++++++++++
1) insert at the beginning
2) insert at the end
3) delete from beginning
4) delete from the end
5) display the linked list
6) exit
+++++++++++++++++++++++++++++++++++++++++++++

-> Enter your choice: 6

Process returned 0 (0x0)   execution time : 51.699 s
Press any key to continue.
