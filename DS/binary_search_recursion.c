//implementing binary search using recursive method..

#include<stdio.h>
#include<stdlib.h>

int binary_search(int arr[],int low,int high,int ele)
{
    if(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == ele)
            return 1;
        if(arr[mid] > ele)
            return binary_search(arr,low,mid - 1,ele);
        else
            return binary_search(arr,mid + 1,high,ele);       
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
    int result = binary_search(array,0,size-1,ele);
    if(result == -1)
    {
        printf("element not found.\n");
    }
    else
    {
        printf("element found.\n");
    }
}