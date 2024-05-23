// implementing selection sort 

#include<stdio.h>
#include<stdlib.h>

int selection_sort(int arr[],int size)
{
    int min;
    for(int i=0;i<size;i++)
    {
        min = i;
        for(int j = i+1;j<size;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp;
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    selection_sort(array,size);
    printf("elements after sorted:\n");
    for(int i = 0;i<size;i++)
    {
        printf("%d  ",array[i]);
    }
}