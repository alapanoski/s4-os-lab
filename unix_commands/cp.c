#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    FILE *fp1, *fp2;
    char buf[BUFFER_SIZE];

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");

    while (fgets(buf, BUFFER_SIZE, fp1) != NULL)
        fputs(buf, fp2);

    return 0;
}