// program to print the prime fibonacci numbers 

#include<stdio.h>
void main()
{
    int n;
    printf("enter the range:\n");
    scanf("%d",&n);
    int a = 0;
    int b = 1;
    int temp=0;
    for(int i = 0;temp<n;i++)
    {
        int count = 0;
        temp = a +b;
        a = b;
        b = temp;
        //printf("%d ",b);
        if(b<3){
            continue;
        }
        else{

            for(int j=1;j<=b/2;j++)
            {
                if(b%j==0){
                    count++;
                }
            }
        if(count==1)
        {
            printf("%d ",b);
        }
        else
        {
            continue;
        }
    }
    }
}