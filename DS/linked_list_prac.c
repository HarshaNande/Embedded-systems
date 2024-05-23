#include<stdio.h>
#include<stdlib.h>

void insert_begin(int);
void display();
void insert_end(int);
void insert_after(int,int);
void insert_before(int,int);
int delete_first();
int delete_end();
int delete_specific(int);
void reverse();

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void main()
{
    int ch,ele,sele;
    while(1)
    {
        printf("\n");
        printf(".....Linked list operations....\n");
        printf("1.Insert_begin\n2.Display\n3.Insert_end\n4.Insert_after\n5.Insert_before\n6.delete_first\n7.delete_last\n8.delete_specific\n9.Reverse\n10.Exit\n");
        printf(".......Select the choice.......\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element:\n");
                    scanf("%d",&ele);
                    insert_begin(ele);
                    break;

            case 2: display();
                    break;

            case 3: printf("enter the element:\n");
                    scanf("%d",&ele);   
                    insert_end(ele);
                    break;   

            case 4: printf("enter the element:\n");
                    scanf("%d",&ele);
                    printf("enter the required element: \n");
                    scanf("%d",&sele);
                    insert_after(ele,sele);
                    break;  

            case 5: printf("enter the element:\n");
                    scanf("%d",&ele);
                    printf("enter the required element: \n");
                    scanf("%d",&sele);
                    insert_before(ele,sele);
                    break; 

            case 6: delete_first();
                    break;   

            case 7: delete_end();
                    break;    

            case 8: printf("enter the required element: \n");
                    scanf("%d",&sele);
                    delete_specific(sele);
                    break;

            case 9: reverse();
                    break;

            case 10: exit(0);
            default: printf("Invalid choice.\n");        
        }
    }    
}

void insert_begin(int ele)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void display()
{
    if(start == NULL)
    {
        printf("linked list is empty.\n");
    }
    else
    {
        struct node *temp;
        temp = start;
        while(temp!= NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void insert_end(int ele)
{
    if(start == NULL)
    {
        printf("linked list is empty.\n");
    }
    else
    {
        struct node * temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = ele;
        temp->next = NULL;
        struct node *curr;
        curr = start;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;

    }
}

void insert_after(int ele,int sele)
{
    if(start == NULL)
    {
        printf("list is empty.\n");
    }
    else
    {
        struct node *temp,*curr;
        curr = start;
        while(curr!= NULL && curr->data != sele)
        {
            curr = curr->next;
        }
        if(curr!= NULL)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = ele;
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            printf("element not found.\n");
        }
    }
}

void insert_before(int ele,int sele)
{
    struct node *temp,*curr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    if(start == NULL)
    {
        printf("list is empty.\n");
    }
    else
    {
        if(start->data==sele)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            curr = start;
            while(curr->next!= NULL && curr->next->data != sele)
            {
                curr = curr->next;
            }
            if(curr->next!= NULL)
            {
                temp->next = curr->next;
                curr->next = temp;
            }
            else
            {
                printf("element not found.\n");
            }
        }   
    }
}

int delete_first()
{
    int x=-1;
    if(start == NULL)
    {
        printf("no element to delete list is empty.\n");
    }
    else
    {
        struct node* temp;
        temp=start;
        x = temp->data;
        printf("deleted element is %d.\n",x);
        start = temp->next;
        free(temp);
        temp = NULL;
    }
}

int delete_end()
{
    if(start == NULL)
    {
        printf("no element to delete in list.\n");
    }
    else
    {
        int x;
        struct node *temp,*curr;
        if(start->next == NULL)
        {
            temp = start;
            x = temp->data;
            printf("deleted element is %d.\n",x);
            start = NULL;
            free(temp);
        }
        else
        {
            curr = start;
            while(curr->next->next!=NULL)
            {
                curr=curr->next;
            }
            temp = curr->next;
            x = temp->data;
            printf("deleted element is %d.\n",x);
            curr->next = NULL;
            free(temp);
        }
    }
}

int delete_specific(int sele)
{
    if(start == NULL)
    {
        printf("no element to delete specifically.\n");
    }
    else
    {
        struct node *temp,*curr;
        if(start->data == sele)
        {
            temp = start;
            start = temp->next;
            free(temp);
            temp = NULL;
        }
        else
        {
            curr = start;
            while(curr->next!= NULL && curr->next->data!=sele)
            {
                curr = curr->next;
            }
            if(curr->next!= NULL)
            {
                temp=curr->next;
                curr->next = temp->next;
                free(temp);
                temp = NULL;
            }
            else
            {
                printf("element not found.\n");
            }
        }
    }
}

void reverse()
{
    struct node*curr = start,*prev = NULL,*next;
    if(start == NULL)
    {
        printf("list is empty.\n");
    }
    else
    {
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start = prev;
        printf("reversed linked list elements are:\n");
        struct node * temp = start;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}