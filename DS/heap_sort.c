// implementing heap sort

#include<stdio.h>
#include<stdlib.h>
void heapify(int arr[],int size,int i)
{
    int highest = i;
    int leftside = 2 * i + 1;
    int rightside = 2 * i + 2;

    if(leftside < size && arr[leftside] > arr[highest])
    {
        highest = leftside;
    }
    if(rightside < size && arr[rightside] > arr[highest])
    {
        highest = rightside;
    }
    if(highest != i)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[highest];
        arr[highest] = temp;
        heapify(arr,size,highest);
    }
}
void heap_sort(int arr[],int size)
{
    for(int i = size/2 -1;i >= 0;i--)
    {
        heapify(arr,size,i);
    }
    for(int i = size-1;i >= 0;i--)
    {
        int temp;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
}
void main()
{
    int arr[10] = {4,13,18,2,7,16,11,14,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    heap_sort(arr,size);
    printf("elements after the heap sort.\n");
    for(int i =0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}    