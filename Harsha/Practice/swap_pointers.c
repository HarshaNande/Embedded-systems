//swapping two numbers using integer ppointers

#include<stdio.h>
int swap(int *,int *);
int swap(int * num1,int * num2)
{
    int temp;
    // printf("temp value %d\n",*temp);
    temp = *num1;
    
    *num1 = *num2;
    *num2 = temp;
}
int main()
{
    int a,b;
    printf("enter the values:\n");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("after swapping: %d %d",a,b);
    return 0;
}