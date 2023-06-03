#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    else if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
    }

    else
    {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}