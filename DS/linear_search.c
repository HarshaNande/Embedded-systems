// // implementing linear search or sequential search..

#include<stdio.h>
#include<stdlib.h>

int linear_search(int arr[],int size,int ele)
{
    for(int i =0;i<size;i++)
    {
        if(ele == arr[i])
        {
            return 1;
        }
        else
        {
            continue;
        }
    }
    return -1;
}

void main()
{
    int size;
    printf("enter the size of the array:\n");
    scanf("%d",&size);
    int array[size];
    printf("enter the array elements:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    int ele;
    printf("enter the element you need to find:\n");
    scanf("%d",&ele);
    int result = linear_search(array,size,ele);
    if(result == -1)
    {
        printf("element not found.\n");
    }
    else
    {
        printf("element found.\n");
    }
}