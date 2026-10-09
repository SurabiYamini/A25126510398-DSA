#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;   
};
struct node* head=NULL;
struct node* tail=NULL;
struct node* createNode(int value)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insertBeginning(int value)
{
    struct node* newnode=createNode(value);
    if(head==NULL)
    {
    head=newnode;
    tail=newnode;
    }
    else
    {
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    }
}
void insertEnd(int value)
{
 struct node* newnode=createNode(value);
 if(head==NULL)
 {
    head=newnode;
    tail=newnode;
 }
 else
 {
  tail->next=newnode;
  newnode->prev=tail;
  tail=newnode;
 }
}
void insertAfter(int key,int value)
{
  struct node* newnode=createNode(value);
  struct node* temp=head;
  while(temp->data!=key)
  {
    temp=temp->next;
  }
  if(temp==tail)
  {
    insertEnd(value);
  }
  else
  {
 
  newnode->next=temp->next;
  newnode->prev=temp;

  temp->next->prev=newnode;
  temp->next=newnode;
  
  }
}
void insertBefore(int key,int value)
{
  struct node* newnode=createNode(value);
  struct node* temp=head;
  while(temp->data!=key)
  {
    temp=temp->next;
  }
  if(temp==head)
  {
    insertBeginning(value);
  }
  else
  {
  newnode->prev=temp->prev;
  temp->prev->next=newnode;
  temp->prev=newnode;
  newnode->next=temp;
  }
}
void deleteFirst()
{
    if(head==NULL)
    {
        printf("list is empty.");
        return;
    }
    else
    {
    struct node* temp=head;
    head=temp->next;
    temp->next=NULL;
    head->prev=NULL;
    printf("%d is deleted.\n",temp->data);
    free(temp);
    }
}
void deleteLast()
{
    if(head==NULL)
    {
        printf("list is empty.");
        return;
    }
    else
    {
    struct node* temp=tail;
    tail=temp->prev;
    temp->prev=NULL;
    tail->next=NULL;
    printf("%d is deleted.\n",temp->data);
    free(temp);
    }
}
void deleteNode(int key)
{
    if(head==NULL)
    {
        printf("list is empty.");
        return;
    }
    else
    {
    struct node* temp=head;
    while(temp->data!=key)
    {
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("%d is deleted.\n",temp->data);
    free(temp);
    }
}
void searchNode(int key)
{
    if(head==NULL)
    {
        printf("list is empty.");
        return;
    }
    struct node* temp=head;
    while(temp!=NULL)
    {
    if(temp->data==key)
    { 
    printf("%d node is found.\n",temp->data);
    return;
    }
    temp=temp->next;
    }
    printf("Node not found!!\n");
}
void displayforward()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("list is empty.");
        return;
    }
   temp=head;
   while(temp!=NULL)
   {
    printf("%d\t",temp->prev);
    printf("%d\t",temp->data);
    printf("%d\n",temp->next);
    temp=temp->next;
   }
}
void displayBackward()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("list is empty.");
        return;
    }
   temp=tail;
   while(temp!=NULL)
   {
    printf("%d\t",temp->prev);
    printf("%d\t",temp->data);
    printf("%d\n",temp->next);
    temp=temp->prev;
   }
}
int main()
{
   int value,choice,key;
   while(1)
   {
   printf("\n***Menu***\n1.Insert a node at beginning\n2.Insert a node at end\n3.Insert a node after node\n4.Insert a node before node\n5.delete first node\n6.delete last node\n7.delete in between node\n8.Search given element\n9.display forward\n10.display backward\n11.exit\nenter the choice:");
   scanf("%d",&choice);
   
    switch(choice)
    {
        case 1:printf("enter the value:");
               scanf("%d",&value);
               insertBeginning(value);
               printf("Insertion success!!\n");
               break;
        case 2:printf("enter the value:");
               scanf("%d",&value);
               insertEnd(value);
               printf("Insertion success!!\n");
               break;
        case 3:printf("enter the key:");
               scanf("%d",&key);
               printf("enter the value:");
               scanf("%d",&value);
               insertAfter(key,value);
               printf("Insertion success!!\n");
               break;
        case 4:printf("enter the key:");
               scanf("%d",&key);
               printf("enter the value:");
               scanf("%d",&value);
               insertBefore(key,value);
               printf("Insertion success!!\n");
               break;
        case 5:deleteFirst();
               break;
        case 6:deleteLast();
               break;
        case 7:printf("enter the node to be deleted:");
               scanf("%d",&key);
               deleteNode(key);
               break;
        case 8:printf("enter the node to search:");
                scanf("%d",&key);
                searchNode(key);
                break;
        case 9:displayforward();
               break;
        case 10:displayBackward();
                break;
        case 11:exit(0);
        default:printf("Invalid choice!!\n");
    }
   }
return 0;
}