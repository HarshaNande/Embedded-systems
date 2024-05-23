//program that defines and int variable and pointer variable

#include<stdio.h>
void main()
{
    int num;
    int *ptr;
    ptr = &num;
    printf("enter the num value:\n");
    scanf("%d",&num);
    printf("num value is: %d\n",num);
    printf("num value by using ptr: %d\n",*ptr);
}