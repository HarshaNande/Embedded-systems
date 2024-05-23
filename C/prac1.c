//taylor series for e^x...

#include<stdio.h>

float taylor_fun(int ,float);

float taylor_fun(int number,float a)
{
    float sum = 0;
    for(int i=number -1;i>0;i--)
    {
        sum= 1 + a * sum/i;
    }
    return sum;
}
void main()
{
    int n;
    printf("enter the number of terms:\n");
    scanf("%d",&n);   //no of terms for the taylor series
    float x = 5.0;  //value of x in e^x

    //check whether if n and x are greater than 0

    if(n>0 && x> 0)
    {
        printf("value of n is %d and x is %f\n",n,x);
        printf("e^x is %f",taylor_fun(n,x));
    }
}