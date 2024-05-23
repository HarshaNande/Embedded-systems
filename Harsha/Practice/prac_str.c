// #include<stdio.h>
// void main()
// {
//     struct dob
//     {
//         int dd;
//         int mm;
//         int yy;
//     };
//     struct dob date1 = {01,11,1996},date2;
//     date2 = date1;
//     printf("date is : %d\n",date2.dd);
//     printf("month is : %d\n",date2.mm);
//     printf("year is : %d\n",date2.yy);
// }

// #include<stdio.h>
// struct student
// {
//     char *name;
// };
// struct student s;
// struct student fun(void)
// {
//     s.name = "newton";
//     printf("%s\n",s.name);
//     s.name = "ajay";
//     return s;
// }
// void main()
// {
//     struct student m = fun();
//     printf("%s\n",m.name);
//     m.name = "teja";
//     printf("%s\n",m.name);
// }

// #include<stdio.h>
// struct student 
// {
//     char * name;
// };
// void main()
// {
//     struct student m,s;
//     s.name = "at";
//     m = s;
//     printf("%s ",m.name);
//     printf("%s ",s.name);
// }

// #include<stdio.h>
// struct student 
// {

// };
// void main()
// {
//     struct student s[2];
//     printf("%ld\n",sizeof(s));
// }

// #include<stdio.h>
// void fun(char []);
// void fun(char *arr)
// {
//     printf("%s\n",arr);
// }
// void main()
// {
//     char str[10] = "hello\0";
//     fun(str);
// }

#include<stdio.h>

struct members
{
    unsigned int first:2;
    unsigned int second:10;
};
void main()
{
    struct members n;
    n.first = 3;
    n.second = 67;
    printf("first number is :%d\n",n.first);
    printf("second number is :%d\n",n.second);
    printf("size of int id %ld\n",sizeof(unsigned int));
    printf("size of structure id %ld\n",sizeof(struct members));
}
