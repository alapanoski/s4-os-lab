#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int r = fork();

    if (r == -1)
    {
        printf("Error in process\n");
        exit(1);
    }

    else if (r == 0)
    {
        int pid = getpid();
        printf("Successfully forked process\n");
        printf("PID: %d\n", pid);
    }

    printf("Program to demonstrate fork()\n");

    return 0;
}