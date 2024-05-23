//initializing an integer array and printing

#include<stdio.h>
void rfun(int rev[5])
{
    //int rev[5];
    int i;
    printf("reversed array is :\n");
    for(i=4;i>=0;i--)
    {
        printf("%d ",rev[i]);
    }
}
void main()
{
    int arr[5] = {10,20,30,40,50};
    int sum=0;
    int min,max;
    printf("printing the array elements:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
        sum += *(arr + i);
    }
    printf("\n");
    printf("sum is: %d\n",sum);
    min = arr[2];
    max = arr[2];
    for(int i=0;i<5;i++)
    {
        if(min>arr[i])
        {
            min = arr[i];
        }
        else if(max<arr[i])
        {
            max = arr[i];
        }
    }
    printf("minimum value is: %d\n",min);
    printf("maximum value is: %d\n",max);
    rfun(arr);
}