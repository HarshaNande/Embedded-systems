#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
    int id;
    printf("before fork..\n");
    id = fork();
    //printf("id is : %d\n",id);
    // if(id == 0)
    // {
    //     printf("in child process..: %d\n",id);
    //     fork();
    // }
    // else
    // {
    //     printf("in parent process..: %d\n",id);
    // }
    if(id != 0)
    {
        fork();
    }
    printf("hello world\n");
    return 0;
}
