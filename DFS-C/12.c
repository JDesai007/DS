#include<stdio.h>
#include<stdlib.h>

struct node
{

    int data;
    struct node *pre;
    struct node *next;
};

struct node* insert(struct node *head,int ele)
{
    struct node *n,*prev,*curr;

   n=(struct node*)malloc(sizeof(struct node)) ;
    n->data=ele;
   
    if(head==NULL)
    {
      
        n->pre=n;
        n->next=n;
        head=n;
        return head;
    }
   curr=head;
   prev=NULL;
        do
        {
              prev=curr;
             curr=curr->next;
             if (curr == head || ele < curr->data) {
              break;
             }
        }while (curr!=head);
            
            n->next=curr;
            n->pre=prev;
            prev->next=n;
            curr->pre=n;
   if (curr == head && ele< head->data) {
        head = n;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;

    do
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }while (temp!=head);
  
    
    
}



void main()
{
    struct node *head=NULL;

    int ele,c;

    while(1)
    {
        printf("\n1:insert");
        printf("\n2:delete");
        printf("\n3:display");
        printf("\n4:exit");
        printf("\nEnter your choice:");
        scanf("%d",&c);

        switch (c)
        {
        case 1:printf("\nEnter Element:");
               scanf("%d",&ele);
               head=insert(head,ele);
               break;
        case 2:break;

        case 3:display(head);
        
        default:
            break;
        }
        
    }

}
