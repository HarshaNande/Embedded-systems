// implementing bubble sort

#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j = 0;j<size-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return *arr;
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
    printf("elements after sorted:\n");
    bubble_sort(array,size);
    for(int i = 0;i<size;i++)
    {
        printf("%d  ",array[i]);
    }
}    