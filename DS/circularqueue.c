#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int *q;
    int size;
    int front;
    int rear;
};
struct queue que;
void enque(int);
int overflow();
void display();
int deque();
int underflow();
int main()
{
    que.q=NULL;
    que.size=0;
    que.front=-1;
    que.rear=-1;
    int i;
    printf("enter the size of queue:\n");
    scanf("%d",&que.size);
    que.q=(int*)malloc(sizeof(int)*que.size);
    int ele;
    printf("enter the elements in queue:\n");
    for(i=0;i<que.size;i++)
    {
        scanf("%d",&ele);
        enque(ele);
    }
    printf("elements before deque:\n");
    display();
    deque();
    printf("\nelements in que after deque:");
    display();
}
void enque(int ele)
{
if(!overflow())
{
    if(que.front=-1)
        que.front++;
        que.rear=(que.rear+1)%que.size;
        que.q[que.rear]=ele;

}
else
{
 printf("queue is full\n");
}
}
int overflow()
{
    if(que.rear==(que.rear+1)%que.size)
    return 1;
    return 0;
}
void display()
{
    printf("elements:\n");
    for(int i=que.front;i!=que.rear;i=(i+1)%que.size)
    {
        printf("%d",que.q[i]);
    }
    printf("\n%d",que.q[que.rear]);
}
int deque()
{
    int x=-999;
    if(!underflow())
    {
        x=que.q[que.front];
        if(que.front==que.rear)
         {
            que.front=que.rear=-1;
         }
         else
         {
            que.front=(que.front+1)%que.size;
         }
         return x;
    }
    else
    {
      printf("queue is empty");
    }
}
int underflow()
{
    if(que.front==-1 && que.rear==-1)
    return 1;
    return 0;
}