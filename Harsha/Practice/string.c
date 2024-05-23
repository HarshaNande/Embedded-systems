//working on strings

#include<stdio.h>
void main()
{
    char a[] = "string";
    int count = 0;
    for(int i=0;a[i]!='\0';i++)
    {
        count++;
    }
    printf("length of string is :%d\n",count);
    printf("size of string is : %ld\n",sizeof(a));
}