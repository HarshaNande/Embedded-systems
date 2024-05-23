//implementing of queue using linked list....

#include<stdio.h>
#include<stdlib.h>

void enqueue(int);
void dequeue();
void display();

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int main()
{
    int ch,ele;
    while(1)
    {
        printf("\n............Queue operations using linked list.........\n");
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
    return 0;
}

void enqueue(int ele)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;
    if(front == NULL && rear == NULL)
    {
        rear = front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("\nunderflow\n");
    }
    else
    {
        struct node *temp;
        temp = front;
        printf("popped element is %d\n",front->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    if(rear == NULL && front == NULL)
    {
        printf("queue is empty.\n");
    }
    else
    {
        printf("the queue is : \n");
        struct node* temp;
        temp = front;
        while(temp)
        {
            printf("%d -->",temp->data);
            temp =temp->next;
        }
    }
}
