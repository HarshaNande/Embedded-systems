//performing double linked list operations

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
void reverse();

struct node 
{
    int data;
    struct node *next,*prev;
};

struct node *start = NULL;

void main()
{
    int ch,element;
    int sele;
    printf("\n");
    printf(".....Double_Linked_list operations....\n");
    printf("1.Insert_begin\n2.Display\n3.Insert_end\n4.Insert_after\n5.Insert_before\n6.delete_first\n7.delete_last\n8.delete_specific\n9.traverse_forward\n10.traverse_backward\n11.Reverse\n12.Exit\n");
    while(1)
    {
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
            case 11: reverse();
                     break;         
            case 12: 
                     free(start);
                     start=NULL;
                     exit(0);              
            default: printf("entered invalid choice.\n");     
                     break;   
        }             
    }    
}

void insert_begin(int ele)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    if(start == NULL)
    {
        temp->next = temp->prev = NULL;
        start = temp;
    }
    else
    {
        temp->next = start;
        temp->prev = NULL;
        start->prev = temp;
        start = temp;
    }
}

void display()
{
    if(start==NULL)
    {
        printf("linked list is empty.\n");
    }
    else
    {
        printf("linked list elements are: \n");
        struct node* temp;
        temp = start;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void insert_end(int ele)
{
    struct node* temp, *curr;
    temp = malloc(sizeof(struct node));
    curr = start;
    temp->data = ele;
    temp->next = NULL;
    if(start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}

void insert_after(int ele,int sele)
{
    struct node *temp,*curr;
    if(start != NULL)
    {
        curr = start;
        while(curr!=NULL && curr->data != sele)
        {
            curr = curr->next;
        }
        if(curr!= NULL)
        {
            temp = malloc(sizeof(struct node));
            temp->data = ele;
            temp->prev = curr;
            temp->next = curr->next;
            if(curr->next!=NULL)
            {
                curr->next->prev = temp;
            }
            curr->next = temp;
        }
        else
        {
            printf("element not found.\n");
        }
    }
    else
    {
        printf("list is empty.\n");
    }
}

void insert_before(int ele,int sele)
{
    struct node * temp, *curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    if(start!= NULL)
    {
        if(start->data == sele)
        {
            temp->next = start;
            temp->prev = NULL;
            start = temp;
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
                temp->next = curr->next;
                temp->prev = curr;
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
    struct node* temp;
    int x = -99;
    if(start == NULL)
    {
        printf("list is empty no element to delete.\n");
    }
    else
    {
        if(start->next == NULL)
        {
            x = start->data;
            free(start);
            start = NULL;
        }
        else
        {
            temp = start;
            x = temp->data;
            start = temp->next;
            temp->next->prev = NULL;
            free(temp);
            temp = NULL;
        }
    }
   return x;
}

int delete_last()
{
    struct node* temp,*curr;
    int x=-999;
    if(start == NULL)
    {
        printf("list is empty no element to delete.\n");
    }
    else
    {
        if(start->next == NULL)
        {
            temp=start;
            x=temp->data;
            free(temp);
            temp = NULL;
        }
        else
        {
            curr = start;
            while(curr->next->next!= NULL)
            {
                curr = curr->next;
            }
            temp=curr->next;
            x = temp->data;
            curr->next = NULL;
            free(temp);
            temp = NULL;
        }
    }
    return x;
}

void delete_specific(int sele)
{
    struct node* curr;
    if(start==NULL)
    {
        printf("list is empty.\n");
    }
    else
    {
        curr = start;
        while(curr!=NULL && curr->data!=sele)
        {
            curr = curr->next;
        }
        if(curr!=NULL)
        {
            if(curr->prev == NULL)
            {
                start=curr->next;
            }
            else
            {
                curr->prev->next = curr->next;
            }
            if(curr->next!= NULL)
            {
                curr->next->prev = curr->prev;
            }
        }
        else
        {
            printf("element not found.\n");
        }
    }
}
/*void delete_specific(int sele)
{
    struct node *temp,*curr;
    if(start != NULL)
    {
        if(start->data == sele)
        {
            temp = start;
            start = temp->next;
            free(temp);
        }
        else
        {
            curr = start;
            while(curr->next!= NULL && curr->next->data!= sele)
            {
                curr = curr->next;
            }
            if(curr!= NULL)
            {
                temp = curr->next;
                curr->next = temp->next;
                temp->next->prev = curr;
                free(temp);
                temp = NULL;
            }
            else
            {
                printf("element not found.\n");
            }
        }
    }
    else
    {
        printf("list is empty no elements to delete.\n");
    }
}*/

void traverse_forward()
{
    if(start==NULL)
    {
        printf("linked list is empty.\n");
    }
    else
    {
        printf("traverse forward double linked list elements are: \n");
        struct node* temp;
        temp = start;
        while(temp!=NULL)
        {
            printf("%p ",temp->next);
            printf("%d  ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void traverse_backward()
{
    struct node* curr;
    printf("traverse backward double list elements are:\n");
    if(start!= NULL)
    {
        curr = start;
        while(curr->next!= NULL)
        {
            curr = curr->next;
        }
        while(curr->prev!=NULL)
        {
            printf("%p ",curr->next);
            printf("%d  ",curr->data);
            curr = curr->prev;
        }
        printf("%p ",curr->next);
        printf("%d  ",curr->data);
    }
    printf("\n");
}

void reverse()
{
    struct node * temp,*curr;
    curr = start;
    temp = NULL;
    while(curr!=NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    start = temp->prev;
    if(start==NULL)
    {
        printf("linked list is empty.\n");
    }
    else
    {
        printf("reversed double linked list elements are: \n");
        struct node* temp;
        temp = start;
        while(temp!=NULL)
        {
            printf("%p ",temp->next);
            printf("%d  ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}