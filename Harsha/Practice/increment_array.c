//write a function of increment array 

#include<stdio.h>
int increfun(int [],int);
int increfun(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        array[i] = array[i] + 1;
    }
}
int main()
{
    int n;
    int arr[n];
    printf("enter the range:\n");
    scanf("%d",&n);
    printf("enter the elements of array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    increfun(arr,n);
    printf("elements after incrementing:\n");
    for(int i=0;i<n;i++)
    {
         printf("%d ",arr[i]);
    }
    return 0;
}