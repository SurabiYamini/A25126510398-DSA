/* A service centre uses a fixed-size request buffer in which released positions must be reused. 
Write a C program to implement a Circular Queue using an array with insertion, deletion, display, 
overflow and underflow operations. Demonstrate that positions freed after deletion can be reused 
for new requests. */

#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}
int isEmpty() {
    return (front == -1);
}
void insert(int value)
{
    if (isFull())
        {
        printf("Queue Overflow\n");
        return;
        }
    if (isEmpty())
        {
        front = 0;
        }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
    printf("Insertion success!!\n");
}

int delete() 
{
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear)
        {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}
void display()
 {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue : ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
         break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
int main()
{
   int value,choice;
   while(1)
   {
   printf("\n***CIRCULAR QUEUE ****\n1.Insert\n2.Delete\n3.display\n4.exit\nenter the choice:");
   scanf("%d",&choice);
   
    switch(choice)
    {
        case 1:printf("enter the value:");
               scanf("%d",&value);
               insert(value);
               break;
        case 2:delete();
               break;
        case 3:display();
                break;
        case 4:exit(0);
        default:printf("Invalid choice!!\n");
    }
   }
return 0;
}
