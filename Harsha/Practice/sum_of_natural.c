//sum of natural numbers using recursion
#include<stdio.h>
int sum_of_n(int);
int sum_of_n(int number)
{
    if(number==0)
    return 0;
    else if(number==1)
    return 1;
    else
    return number + sum_of_n(number - 1);
}
void main()
{
    int n;
    printf("enter the range of natural numbers:\n");
    scanf("%d",&n);
    printf("sum of natural numbers is:%d\n",sum_of_n(n));
}