//implementing binary search using iterative method...
#include<stdio.h>
#include<stdlib.h>

int binary_search(int arr[],int size,int ele)
{
    int low = 0,high = size-1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == ele)
        {
            return 1;
        }
        if(arr[mid] < ele)
        {
            low = mid+1;
        }
        else
        {
            high = mid -1;
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
    int result = binary_search(array,size,ele);
    if(result == -1)
    {
        printf("element not found.\n");
    }
    else
    {
        printf("element found.\n");
    }
}