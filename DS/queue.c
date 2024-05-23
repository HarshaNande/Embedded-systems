// implementing linear queue using array implementation.....

#include<stdio.h>
#include<stdlib.h>

void enqueue(int);
void dequeue();
void display();
void peek();

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int ch,ele;
    while(1)
    {
        printf("\n............Queue operations.........\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.peek\n5.quit\n");
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
            case 4: peek();
                    break;
            case 5: exit(0);
            default:printf("\nInvalid choice.\n");                                
        }
    }
    return 0;
}
int isFull()
{
    if(rear == MAX-1)
        return 1;
    else
        return 0;    
}

int isEmpty()
{
    if(front == -1 && rear == -1)
        return 1;
    else 
        return 0;    
}

void enqueue(int ele)
{
    if(isFull())
    {
        printf("queue is full,overflow condition occurred.\n");
    }    
    else
    {
        if(front == -1)
        {
            front++;
        }    
        rear++;
        queue[rear] = ele;    
    }    
}

void dequeue()
{
    if(isEmpty())
    {
        printf("queue is empty,underflow condition occurred.\n");
    }
    else
    {
        printf("popped element is %d\n",queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    if(rear == -1)
    {
        printf("queue is empty no elements to display.\n");
    }
    else
    {
        printf("queue elements are: \n");
        for(int i=front;i<= rear;i++)
        {
            printf("%d  ",queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if(isEmpty())
    {
        printf("queue is empty no elements to peek. \n");
    }
    else
    {
        printf("peeked element is %d.\n",queue[rear]);    
    }
}

