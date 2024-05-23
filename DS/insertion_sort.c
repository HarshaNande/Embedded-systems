//implementing insertion sort 

#include<stdio.h>
#include<stdlib.h>

// void main()
// {
//     int arr[10] = {4,13,18,2,7,16,11,14,6,9};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int key,j;
//     for(int i=1;i<size;i++)
//     {
//         key = arr[i];
//         j = i-1;
//         while(j>=0 && arr[j] > key)
//         {
//             arr[j+1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }

int insertion_sort(int arr[],int size)
{
    int key,j;
    for(int i = 1;i<size;i++)
    {
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
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
    insertion_sort(array,size);
    for(int i = 0;i<size;i++)
    {
        printf("%d  ",array[i]);
    }
}    