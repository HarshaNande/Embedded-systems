// #include<stdio.h>
// #include<stdlib.h>
// void enque();
// void display();
// void deque();
// struct node
// {
//     int data;
//     struct node *next;
// };
// struct node *front=0;
// struct node *rear=0;
// int main()
// {
//    int ch,ele;
//     do
//     {
//         printf("\nenter the choice:\n");
//         scanf("%d",&ch);
//         switch(ch)
//         {
//             case 1:printf("enter the element:\n");
//                    scanf("%d",&ele);
//                    enque(ele);
//                    break;

//             case 2:printf("elements in stack are:\n");
//                    display();
//                    break;

//             case 3:deque();
//                    break;

//             default:
//             ;
//         }

//     }while(ch!=0); 
// }
// void enque(int ele)
// {
//     struct node *temp;
//     temp=(struct node *)malloc(sizeof(struct node));
//     temp->data=ele;
//     temp->next=0;
// if(front==0 && rear==0)
// {
//     front=rear=temp;
// }
// else
// {
//     rear->next=temp;
//     rear=temp;
// }
// }
// void display()
// {
//     struct node *curr;
//     if(front==0 && rear==0)
//     {
//         printf("queue is empty\n");
//     }
//     else
//     {
//         curr=front;
//         while(curr!=0)
//         {
//             printf("%d\t",curr->data);
//             curr=curr->next;
//         }
//     }
// }
// void deque()
// {
//     struct node *temp;
//     temp=front;
//     if(front==0&&rear==0)
//     {
//         printf("queue is empty");
//     }
//     else
//     {
//         if(front==rear)
//         {
//             front=rear=0;
//         }
//         else
//         {
//             front=front->next;
//             free(temp);
//             temp=NULL;
//         }
//     }
// }

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
            case 4: peek();
                    break;
            case 5: exit(0);
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
