//performing operations on linked list

#include<stdio.h>
#include<stdlib.h>

void insert_begin(int);
void display();
void insert_end(int);
void insert_after(int,int);
void insert_before(int,int);
int delete_first();
int delete_last();
void delete_specific(int);
void traverse_forward();
void traverse_backward();
void rev_print();

struct node
{
    int data;
    struct node * next;
};

struct node * start= NULL;

void main()
{
    //printf("%ld",sizeof(int));
    int ch,element;
    int sele;
    while(1)
    {
        printf("\n");
        printf(".....Linked list operations....\n");
        printf("1.Insert_begin\n2.Display\n3.Insert_end\n4.Insert_after\n5.Insert_before\n6.delete_first\n7.delete_last\n8.delete_specific\n9.traverse_forward\n10.traverse_backward\n11.Exit\n");
        printf(".......Select the choice.......\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element:\n");
                    scanf("%d",&element);
                    insert_begin(element);
                    break;
            case 2: display();
                    break;  
            case 3: printf("enter the element:\n");
                    scanf("%d",&element);
                    insert_end(element);
                    break;   
            case 4: printf("enter the element:\n");
                    scanf("%d",&element);
                    printf("enter the s_element:\n");
                    scanf("%d",&sele);
                    insert_after(element,sele);
                    break;
            case 5: printf("enter the element:\n");
                    scanf("%d",&element);
                    printf("enter the s_element:\n");
                    scanf("%d",&sele);
                    insert_before(element,sele);
                    break;  
            case 6: delete_first();
                    break;     
            case 7: delete_last();
                    break;    
            case 8: printf("enter the specific_element:\n");
                    scanf("%d",&sele);
                    delete_specific(sele);
                    break;  
            case 9: traverse_forward();
                    break;                           
            case 10: traverse_backward();
                     break;
            case 11: exit(0);              
            default: printf("entered invalid choice.\n");     
                     break;   
        }
    }
}

void insert_begin(int ele)
{
    struct node* temp;
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
        printf("linked list elements are: \n");
        struct node * temp;
        temp = start;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp =temp->next;
        }
    }
    printf("\n");
}

void insert_end(int ele)
{
    struct node* temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node * curr;
        curr = start;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next=temp;
    }
}

void insert_after(int ele,int sele)
{
    struct node *temp,*curr;
    if(start!= NULL)
    {
        curr = start;
        while(curr!= NULL && curr->data != sele)
        {
            curr = curr->next;
        }
        if(curr!=NULL)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = ele;
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            printf("element not found\n");
        }
    }
    else
    {
        printf("list is empty\n");
    }
}

void insert_before(int ele,int sele)
{
    struct node * temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(start!= NULL)
    {
       if(start->data == sele)
        {
            temp->data = ele;
            temp->next = start;
            start = temp;
        }
        else
        {
            curr = start;
            while(curr->next!=NULL && curr->next->data!= sele)
            {
                curr = curr->next;
            }
            if(curr->next!=NULL)
            {
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
    else
    {
        printf("list is empty.\n");
    }
}

int delete_first()
{
    int x = -1;
    struct node * temp;
    if(start!= NULL)
    {
        temp=start;
        x = temp->data;
        start=temp->next;
        free(temp);
        temp=NULL;
    }
    else
    {
        printf("list is empty.\n");
        return -1;
    }
}

int delete_last()
{
    int x=-1;
    struct node *temp,*curr;
    if(start!= NULL)
    {
        if(start->next == NULL)
        {
            temp=start;
            x=temp->data;
            start = NULL;
            free(temp);
        }
        else
        {
            curr=start;
            while(curr->next->next!= NULL)
            {
                curr = curr->next;
            }
            temp=curr->next;
            x=temp->data;
            curr->next = NULL;
            free(temp);
        }
    }
    else
    {
        printf("list is empty.\n");
        return x;
    }    
}

void delete_specific(int sele)
{
    struct node * temp,*curr;
    if(start!= NULL)
    {
        if(start->data==sele)
        {
            temp=start;
            start=temp->next;
            free(temp);
        }
        else
        {
            curr = start;
            while(curr->next!=NULL && curr->next->data!=sele)
            {
                curr = curr->next;
            }
            if(curr->next!=NULL)
            {
                temp=curr->next;
                curr->next = temp->next;
                free(temp);
            }
            else
            {
                printf("element not found.\n");
            }
        }       
    }
    else
    {
        printf("list is empty.\n");
    }
}

void traverse_forward()
{
    struct node* temp;
    if(start==NULL)
    {
        printf("the list is empty.\n");
    }
    else
    {
        temp = start;
        while(temp->next!= NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
        printf("%d  ",temp->data);
    }
}

void traverse_backward()
{
    if(start!=NULL)
    {
        rev_print(start);
    }
    else
    {
        printf("The list is empty.\n");
    }
}

void rev_print(struct node * curr)
{
    if(curr->next!=NULL)
    {
        rev_print(curr->next);
        printf("%d  ",curr->data);
    }
    else
    {
        printf("%d  ",curr->data);
    }
}
