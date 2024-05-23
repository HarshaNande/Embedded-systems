// factorial of a number using iterative method

#include<stdio.h>
void main()
{
    int fact = 1;
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    for(int i =1;i<=n;i++)
    {
        fact = fact * i;
    }
    printf("factorial of %d is: %d\n",n,fact);
}