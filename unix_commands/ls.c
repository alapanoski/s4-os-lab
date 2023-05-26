#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    DIR *p;
    struct dirent *d;

    p = opendir(argv[1]);
    if (p == NULL)
    {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    while ((d = readdir(p)) != NULL)
        printf("%s\t", d->d_name);
    printf("\n");

    return 0;
}