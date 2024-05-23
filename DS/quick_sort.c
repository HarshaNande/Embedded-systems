//implementing quick sort

#include<stdio.h>

int partition(int [],int,int);
void quick_sort(int [],int,int);

int partition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    int temp;
    while(i<j)
    {
        while(arr[i] <= pivot && i <= high-1)
        {
            i++;
        }
        while(arr[j] > pivot && j >= low+1)
        {
            j--;
        }
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quick_sort(int arr[],int low,int high)
{
    if(low < high)
    {
        int pi = partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}

void main()
{
    int arr[] = {7,2,6,10,15,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,size-1);
    printf("after quick sort elements are:\n");
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
