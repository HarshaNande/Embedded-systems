// sum of the lower diagonal elements 

#include<stdio.h>
int sum_of(int arr[10][10],int rows,int cols);
void main()
{
    int rows,cols;
    printf("enter the no.of rows:\n");
    scanf("%d",&rows);
    printf("enter the no.of columns:\n");
    scanf("%d",&cols);
    int arr[10][10];
    printf("enter the array elements:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int result;
    result = sum_of(arr,rows,cols);
    printf("sum is %d\n",result);
}

int sum_of(int array[10][10],int a,int b)
{
    int sum = 0;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(i>j)
            {
                sum += array[i][j];
            }
        }
    }
    return sum;
}