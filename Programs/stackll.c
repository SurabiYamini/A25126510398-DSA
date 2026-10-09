#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top=NULL;
struct node *createNode(int value)
{
struct node *newnode=malloc(sizeof(struct node));
newnode ->data=value;
newnode ->next=NULL;
}
void push(int value)
{
struct  node *newnode=createNode(value);
newnode->next=top;
top=newnode;
printf("the value %d is pushed!!\n",value);
}
void pop()
{
struct node *temp;
if(top==NULL)
{
printf("stack is empty\n");
return;
}
temp=top;
printf("the popped element is %d\n ",top->data);
top=top ->next;
free(temp);
}
void peek()
{
if(top==NULL)
{
printf("the stack is empty\n");
return;
}
printf("the top element is %d:\n",top-> data);
}
void display()
{
struct node *temp;
if(top==NULL)
{
printf("stack is empty\n");
return;
}

temp=top;
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
printf("\nMENU: 1.push 2.pop 3.peek 4.display 5.exit \nenter the choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the value to be pushed:");
            scanf("%d",&value);
            push(value);
            break;
case 2:pop();
           break;
case 3:peek();
           break;
case 4: display();
           break;
case 5:exit(0);
default:printf("\ninvalid choice!!") ;
}
}
return 0;
}


