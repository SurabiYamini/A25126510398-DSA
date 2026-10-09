#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void push(int value);
void pop();
void display();
int stack[SIZE],top = -1;
void main(){
int value,choice;
while(1){
printf("\n****MENU****\n");
printf("\n\n 1.Push\n 2.Pop\n 3.Dispaly\n 4.Exit\n");
scanf("%d",&choice);
switch(choice){
case 1: printf("Enter the value to be entered:");
        scanf("%d",&value);
        push(value);
        break;
case 2: pop();
        break;
case 3: display();
        break;
case 4: exit(0);
default:printf("\n Wrong Selection!");
}
}
}
void push(int value)
{
if(top==SIZE-1)
{
printf("Stack Overflow!\n");
}
else
{
top++;
stack[top]=value;
printf("Insertion Success!!");
}
}
void pop()
{
if(top==-1)
{
printf("Stack Underflow!\n");
}
else
{
printf("%d is deleted",stack[top]);
top--;
}
}
void display(){
if(top==-1)
  printf("Stack Underflow!\n");
else{
int i;
printf("The Stack Elements are:\n");
for(i=top;i>=0;i--)
  printf("%d\n",stack[i]);
}
}