//implementing circular queue using arrays...

#include<stdio.h>
#include<stdlib.h>

void enqueue(int);
int dequeue();
void display();
#define MAX 5

int front = -1;
int rear = -1;
int circularQueue[MAX];

int main()
{
    int ch,ele;
    while(1)
    {
        printf("\n............Circular Queue operations using Array.........\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.quit\n");
        printf("\nenter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element.\n");
                    scanf("%d",&ele);
                    enqueue(ele);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("\nInvalid choice.\n");                                
        }
    }
}

void enqueue(int ele)
{
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        circularQueue[rear] = ele;
    }
    else if((rear + 1)%MAX == front)  //condition to check queue is full
    {
        printf("Queue is overflow.\n");
    }
    else
    {
        rear = (rear + 1)%MAX;  // rear is incremented
        circularQueue[rear] = ele;
    }
}

int dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("queue is underflow.\n");
    }
    else if(front == rear)
    {
        printf("the dequeued element is %d\n",circularQueue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("the dequeued element is %d\n",circularQueue[front]);
        front = (front + 1)%MAX;
    }
}

void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("queue is empty.\n");
    }
    else
    {
        printf("elements in the queue are:\n");
        for (i = front; i != rear; i = (i + 1) % MAX) 
        {
            printf("%d ", circularQueue[i]);
        }
        printf("%d ", circularQueue[i]);
    }
}