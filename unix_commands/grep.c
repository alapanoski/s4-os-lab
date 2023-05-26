#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{

    char buf[BUFFER_SIZE];

    FILE *fp;

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        exit(1);
    }

    while (fgets(buf, BUFFER_SIZE, fp) != NULL)
        printf("%s", buf);

    fclose(fp);

    return 0;
}