//implementing merge sort

#include<stdio.h>

void merge_sort(int [],int,int);
void merge(int [],int,int,int);

void merge(int arr[],int mid,int low,int high)
{
    int i,j,k,a[50];
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            a[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        a[k] = arr[i];
        k++;
        i++;
    }
    while(j <= high)
    {
        a[k] = arr[j];
        k++;
        j++;
    }
    for(int i = low;i<=high;i++)
    {
        arr[i] = a[i];
    }
}

void merge_sort(int arr[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid + 1,high);
        merge(arr,mid,low,high);
    }
}

void main()
{
    int arr[10]={4,13,18,2,7,16,11,14,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,size-1);
    printf("after merge sort elements are:\n");
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}