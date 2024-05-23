// c program to find the sum of the series of 1 + 11 + 111.....

#include<stdio.h>
void main()
{
    int n,sum = 1,temp=1;
    printf("enter the range of the series:\n");
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a=1;
        for(int j=0;j<i;j++)
        {
            a *= 10;
        }
        temp = temp + a;
        sum += temp;
    }
    printf("sum is : %d",sum);
}