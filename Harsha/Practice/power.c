//finding the power of a number using recursion

#include<stdio.h>
__uint8_t count =0;
int power(int base,int exponent)
{
    if(exponent==0)
    {
        return 1;
    }
    else if(exponent == 1)
    { 
        return base;
    }
    else
    {
        return base * power(base,(exponent - 1));
    }
    
    count++;
    printf("%d",count);
}
int main()
{
    __uint8_t num=2,pow=2;
    // printf("enter the number and power value:\n");
    // scanf("%d %d",&num,&pow);
    int result = power(num,pow);
    printf("%d\n",result);
    return 0;
}