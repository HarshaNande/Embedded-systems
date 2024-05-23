//adding two polynomials using linked list 

#include<stdio.h>
#include<stdlib.h>

struct node* create_first_poly(struct node * );
struct node* create_second_poly(struct node * );
void display(struct node *);
void add_poly(struct node*,struct node*,struct node*);

struct node
{
    int coeff;
    int expo;
    struct node *next;
};
struct node * start = NULL;

void main()
{
    struct node * first = NULL;
    struct node * second = NULL;
    struct node * result = NULL;
    int ch;
    while(1)
    {
        printf("\n");
        printf("1.Create polynomial\n2.Add polynomial\n3.Display\n4.Exit\n");
        printf("......select your choice......\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: first = create_first_poly(first);
                    second = create_second_poly(second);
                    break;
            case 2: add_poly(result,first,second);
                    break;
            case 3: display(first);
                    display(second);
                    break;
            case 4: free(start);
                    exit(0);
            default: printf("you entered invalid choice.\n");
                     break;                        

        }
    }
}

struct node* create_first_poly(struct node * start)
{
    struct node * list;
    int coeff,expo,n;
    printf("enter the number of terms:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("enter the coefficient for the %d term:\n",i);
        scanf("%d",&coeff);
        printf("enter the exponent for the %d term:\n",i);
        scanf("%d",&expo);
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = coeff;
        temp->expo = expo;
        temp->next = NULL;
        if(start == NULL || expo > start->expo)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            list = start;
            while(list->next!= NULL && list->next->expo >= expo)
            {
                list = list->next;
            }
            temp->next = list->next;
            list->next = temp;
        }
    }
    return start;
}

struct node* create_second_poly(struct node * start)
{
    struct node * list;
    int coeff,expo,n;
    printf("enter the number of terms:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("enter the coefficient for the %d term:\n",i);
        scanf("%d",&coeff);
        printf("enter the exponent for the %d term:\n",i);
        scanf("%d",&expo);
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = coeff;
        temp->expo = expo;
        temp->next = NULL;
        if(start == NULL || expo > start->expo)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            list = start;
            while(list->next!= NULL && list->next->expo >= expo)
            {
                list = list->next;
            }
            temp->next = list->next;
            list->next = temp;
        }
    }
    return start;
}

void display(struct node * start)
{
    if(start == NULL)
    {
        printf("no polynomial.\n");
    }
    else
    {
        struct node * temp;
        temp = start;
        while(temp!= NULL)
        {
            printf("(%dx^%d)",temp->coeff,temp->expo);
            temp = temp->next;
            if(temp!= NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void add_poly(struct node* result,struct node * first,struct node * second)
{
    result = (struct node *)malloc(sizeof(struct node));
    result->next = NULL;
    while(first && second)
    {
        if(first->expo > second->expo)
        {
            result->coeff = first->coeff;
            result->expo = first->expo;
            first = first->next;
        }
        else if(first->expo < second->expo)
        {
            result->coeff = second->coeff;
            result->expo = second->expo;
            second = second->next;
        }
        else
        {
            result->coeff = first->coeff + second->coeff;
            result->expo = first->expo;
            first = first->next;
            second = second->next; 
        }
        if(first && second)
        {
            result->next = (struct node*)malloc(sizeof(struct node));
            result = result->next;
            result->next = NULL;
        }
    }
    while (first || second)
    {
        result->next = (struct node*)malloc(sizeof(struct node));
        result = result->next;
        result->next = NULL;
        if(first)
        {
            result->coeff = first->coeff;
            result->expo = first->expo;
            first = first->next;
        }

        else if(second)
        {
            result->coeff = second->coeff;
            result->expo = second->expo;
            second = second->next;
        }
    }
    display(result);
}