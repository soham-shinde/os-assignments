#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(pid<0){
        printf("error");
    }
    else if (pid==0)
    {
        char *arg[] = {"12","123","1","52","234",NULL};
        char *enp[] = {NULL};
        if(execve("./sortFile",arg,enp)==-1){
            printf("error");
            return 0;
        }
    }
    else{
        printf("\n parend id %d",(int)getppid());
        wait(NULL);
    }
    
    return 0;
}
