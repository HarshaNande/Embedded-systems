//ncr program....

#include<stdio.h>
int fact(int);

int fact(int a)
{
    int fact = 1;
    for(int i=1;i<=a;i++)
    {
        fact = fact * i;
    }
    return fact;
}
void main()
{
    int n,r;
    int ncr;
    printf("enter the values of n,r:\n");
    scanf("%d %d",&n,&r);
    ncr = fact(n) / (fact(n-r) * fact(r));
    printf("the value of ncr is : %d\n",ncr);
}