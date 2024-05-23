//merging two sorted linked lists and generate a third list ...

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

struct node * start = NULL;

struct node* Create (int A[], int n)
{
    int i;
    struct node *t, *last,*temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = A[0];
    temp->next = NULL;
    last = temp;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return temp;
}

void Display(struct node *p)
{
    //struct node *p;
    while (p != NULL)
    {
        printf ("%d ", p->data);
        p = p->next;
    }
}

void Merge(struct node *first, struct node *second)
{
    struct node * third, * last;
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    if (first != NULL)
        last->next = first;
    else
        last->next = second;
}

int main()
{
    int A[] = { 1,3,5,7 };
    int B[] = { 2,6,8,9};
    struct node * first = NULL;
    struct node * second = NULL;
    struct node * third = NULL;
    first = Create (A, 4);
    second = Create (B, 4);

    printf ("1st Linked List: ");
    Display (first);

    printf ("\n2nd Linked List: ");
    Display (second);

    Merge (first, second);

    printf ("\n\nMerged Linked List: \n");
    Display (third);
  return 0;
}