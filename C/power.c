// power a variable using iterative method...

#include<stdio.h>
void main()
{
    int base,exponent;
    int sum = 1;
    printf("enter the base value:\n");
    scanf("%d",&base);
    printf("enter the exponent value:\n");
    scanf("%d",&exponent);
    for(int i=1;i<=exponent;i++)
    {
        sum = sum * base;
    
    }
    printf("the value is:%d\n",sum);
}