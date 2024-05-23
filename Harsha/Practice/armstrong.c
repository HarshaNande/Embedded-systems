#include<stdio.h>
int main()
{
    int num,count=0;
    printf("enter the number:\n");
    scanf("%d",&num);
    int temp = num;
    int a = num;
    int result=0;
    while(temp>0) {
        temp = temp / 10;
        count++;
    }
    //printf("%d\n",count);
    while(num>0) {
        int sum = 1;
        int a = num %10;
        num = num/10;
        for(int i=0;i<count;i++)
        {
            sum = sum * a;
        }
        //printf("%d\n",sum);
        result = result + sum;
    }
    //printf)"%d\n",result);
    if(result == a)
    printf("given number is armstrong\n");
    else
    printf("not an armstrong number.");
    return 0;
}