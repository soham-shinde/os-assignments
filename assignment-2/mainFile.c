#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("error");
    }
    else if (pid == 0)
    {
        char *arg[] = {"12", "123", "1", "52", "234", NULL};
        char *enp[] = {NULL};
        char *path = "/workspaces/os-assignments/assignment-2";
        if (chdir(path) == 0)
        {
            if (execve("./sortFile", arg, enp) == -1)
            {
                perror("execve error");
                return 0;
            }
        }
        else{
            perror("chdir error ");
        }
    }
    else
    {
        printf("\n parent id %d \n", (int)getppid());
        wait(NULL);
    }

    printf("\n\n\n");

    return 0;
}
