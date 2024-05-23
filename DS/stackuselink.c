//implementing stack using linked list 

#include<stdio.h>
#include<stdlib.h>

void push(int);
int pop();
int peek();
void display();

struct node
{
    int data;
    struct node * next;
};

struct node * start = NULL;

int main()
{
    int choice,ele;

    while(1)
    {
        printf("\n.......Stack operations.........\n");
        printf("1.Push\n2.pop\n3.peek\n4.display\n5.exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element:\n");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                ele = pop();
                if(ele != -1)
                {
                    printf("Popped element is %d.\n",ele);
                }
                break;
            case 3:
                ele = peek();
                // printf("Peek element is %d.\n",ele);
                break;
            case 4:
                display();
                break;
            case 5:        
                exit(0);
            default:printf("You entered invalid choice.\n");        
        }
    }
}

void push(int ele)
{
    struct node * temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = ele;
    temp->next = start;
    start = temp;
}

int pop()
{
    int x = -999;
    if(start == NULL)
    {
        printf("\nstack is empty.\n");
        return x;
    }
    else
    {
        struct node * temp = start;
        x = start->data;
        start = start->next;
        free(temp);
        return x;
    }
}

int peek()
{
    if(start == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Peek element is %d.\n",start->data);
    }
}

void display()
{
    struct node * temp;
    temp = start;
    printf("Elements in the stack are:\n");
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}