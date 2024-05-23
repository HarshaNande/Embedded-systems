//sum of terms in taylor series...

#include<stdio.h>

void main()
{
    int n,x,fact = 1,sum = 1;
    printf("enter the x value:\n");
    scanf("%d",&x);
    printf("enter the number of terms:\n");
    scanf("%d",&n);
    
    float res = 0;
    for(int i = 1;i<n;i++)
    {
        fact = fact * i;
        //printf("fact is : %d\n",fact);
        sum = sum * x;
        //printf("power is %d\n",sum);
        res = res + (sum/fact);
    }
    res = res +1;
    printf("%f\n",res);
}
