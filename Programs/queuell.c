#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *createNode(int value)
{
struct node *newnode=malloc(sizeof(struct node));
newnode ->data=value;
newnode ->next=NULL;
}
void enqueue(int value)
{
struct  node *newnode=createNode(value);
if(rear==NULL&&front==NULL)
{
front=rear=newnode;
}
else
{
rear->next=newnode;
rear=newnode;
}
printf("the value %d is enqueued!!\n",value);
}
void dequeue()
{
struct node *temp;
if(front==NULL)
{
printf("queue is empty\n");
return;
}
temp=front;
printf("the dequeued element is %d\n ",front->data);
front=front->next;
free(temp);
}
void display()
{
struct node *temp;
if(front==NULL)
{
printf("queue is empty\n");
return;
}
temp=front;
while (temp!=NULL)
{
printf("%d <->",temp->data);
temp=temp -> next;
}
printf("NULL");
}
int main()
{
int value,choice;
while(1)
{
printf("\nQUEUE MENU:1.enqueue 2.dequeue 3.display 4.exit\nenter the choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the value to be inserted:");
            scanf("%d",&value);
            enqueue(value);
            break;
case 2:dequeue();
           break;
case 3: display();
           break;
case 4:exit(0);
default:printf("\ninvalid choice!!") ;
}
}
return 0;
}

