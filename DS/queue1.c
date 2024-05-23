//implementing queue using stack........

#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int *q;
    int size;
    int rear;
    int front;
};

struct queue que;

void enqueue(int);
void dequeue();
void display();
void peek();

int main()
{
    que.q = NULL;
    que.size = 0;
    que.front = -1;
    que.rear = -1;
    printf("enter the size of the queue:\n");
    scanf("%d",&que.size);
    que.q = (int *)malloc(sizeof(int) * que.size);
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
    if(que.rear == que.size-1)
        return 1;
    else
        return 0;    
}

int isEmpty()
{
    if(que.front == -1 && que.rear == -1)
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
        if(que.front == -1)
        {
            que.front++;
        }    
        que.rear++;
        que.q[que.rear] = ele;    
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
        printf("popped element is %d\n",que.q[que.front]);
        que.front++;
        if(que.front > que.rear)
            que.front = que.rear = -1;
    }
}

void display()
{
    if(que.rear == -1)
    {
        printf("queue is empty no elements to display.\n");
    }
    else
    {
        printf("queue elements are: \n");
        for(int i=que.front;i<=que.rear;i++)
        {
            printf("%d  ",que.q[i]);
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
        printf("peeked element is %d.\n",que.q[que.rear]);    
    }
}