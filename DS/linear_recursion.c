//implementing linear searh using recursion..
#include<stdio.h>
#include<stdlib.h>
int linear_search(int arr[],int size,int ele)
{
    if(size == 0)
        return -1;
    if(arr[size-1] == ele)
        return size-1;
    return linear_search(arr,size-1,ele);        
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