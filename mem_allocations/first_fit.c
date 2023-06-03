#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100

typedef struct
{
    int size;
    int allocated;
} mem_block;

typedef struct
{
    int size;
    int block;
} process;

int main()
{
    int m, n;
    mem_block mem_blocks[MAX_BLOCKS];
    process p[MAX_PROCESS];

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each block: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &mem_blocks[i].size);
        mem_blocks[i].allocated = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].size);
        p[i].block = -1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mem_blocks[j].allocated == 0 && mem_blocks[j].size >= p[i].size)
            {
                mem_blocks[j].allocated = 1;
                p[i].block = j;
                break;
            }

    printf("Proc\tProc Size\tBlock\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t", i + 1, p[i].size);
        if (p[i].block != -1)
            printf("%d\n", p[i].block + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
