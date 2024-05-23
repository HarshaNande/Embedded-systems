//implementing stacks...

#include<stdio.h>
#include<stdlib.h>
//#define size 10    //allocating size of the array statistically

void push(int);
int pop();
int peek();
void display();

struct _stack_
{
    int *s;
    int size;       // allocating size of array dynamically
    int top_of_stack;
};

struct _stack_ sta;

int main()
{
    sta.s = NULL;
    sta.size = 0;
    sta.top_of_stack = -1;

    printf("Enter the size of stack:\n");
    scanf("%d",&sta.size);

    sta.s = (int *)malloc(sizeof(int)*sta.size);  //allocated memory dynamically using malloc.

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
                printf("Peek element is %d.\n",ele);
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

int isEmpty()
{
    if(sta.top_of_stack == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(sta.top_of_stack == sta.size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int ele)
{
    if(!isFull())
    {
        sta.s[++sta.top_of_stack] = ele;
    }
    else
    {
        printf("Stack is full.\n");
    }
}

int pop()
{
    int x = -1;
    if(!isEmpty())
    {
        x = sta.s[sta.top_of_stack--];
    }
    else
    {
        printf("Stack is empty.\n");
    }
    return x;
}

int peek()
{
    int x = -1;
    if(!isEmpty())
    {
        x = sta.s[sta.top_of_stack];
    }
    else
    {
        printf("Stack is empty.\n");
    }
    return x;
}

void display()
{
    printf("Elements in the stack are:\n");
    for(int i=0;i<=sta.top_of_stack;i++)
    {
        printf("%d  ",sta.s[i]);
    }
    printf("\n");
}