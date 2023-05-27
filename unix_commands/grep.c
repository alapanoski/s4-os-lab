#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <pattern> <filename>\n", argv[0]);
        exit(1);
    }

    char pattern[BUFFER_SIZE];
    strncpy(pattern, argv[1], BUFFER_SIZE);

    char buf[BUFFER_SIZE];

    FILE *fp;

    fp = fopen(argv[2], "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        exit(1);
    }

    while (fgets(buf, BUFFER_SIZE, fp) != NULL)
    {
        if (strstr(buf, pattern) != NULL)
            printf("%s", buf);
    }

    fclose(fp);

    return 0;
}
