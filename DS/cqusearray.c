#include<stdio.h>
#define N 5
void enqueue();
void dequeue();
void display();
int queue[N];
int front=-1;
int rear=-1;
int main()
{

   int ch,ele;
    do
    {
        printf("\nenter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the element:\n");
                   scanf("%d",&ele);
                   enqueue(ele);
                   break;

            case 2:printf("elements in queue are:\n");
                   display();
                   break;

            case 3:dequeue();
                   break;

            default:
            ;
        }

    }while(ch!=0);
}
void enqueue(int ele)
{
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=ele;
    }
    else
    {
        if(front==(rear+1)%N)
        {
            printf("queue is empty");
        }
        else
        {
            rear=(rear+1)%N;
            queue[rear]=ele;
        }

    }
}
void dequeue()
{
    if(front=-1&&rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        if(front=rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%N;
        }
    }
}
void display()
{
    int i=front;
    if(front==-1&&rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue is :\n");
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[rear]);
    }
}