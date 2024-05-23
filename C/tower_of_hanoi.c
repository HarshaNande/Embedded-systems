//c program for tower of hanoi

#include<stdio.h>
void towerOfHanoi(int,char,char,char);

void main()
{
    int n;
    printf("enter the no of disks:\n");
    scanf("%d",&n);
    towerOfHanoi(n,'A','C','B');
}

void towerOfHanoi(int num,char frompeg,char topeg,char auxpeg)
{
    if(num == 1)
    {
        printf("move disk 1 frompeg %c topeg %c\n",frompeg,topeg);
        return;
    }
    towerOfHanoi(num-1,frompeg,auxpeg,topeg);
    printf("move disk %d frompeg %c topeg %c\n",num,frompeg,topeg);
    towerOfHanoi(num-1,auxpeg,topeg,frompeg);
}