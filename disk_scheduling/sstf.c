#include <stdio.h>
#include <math.h>

int main()
{
    int p = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &p);

    int disk_queue[p];

    printf("Enter the disk queue: ");
    for (int i = 0; i < p; i++)
        scanf("%d", &disk_queue[i]);

    int head = 0;
    printf("Enter the starting position of head: ");
    scanf("%d", &head);

    int seek_time = 0;
    int min = 9999, min_index = 0;
    for (int i = 0; i < p; i++)
    {
        min = 9999;
        for (int j = 0; j < p; j++)
        {
            if (disk_queue[j] != -1 && abs(head - disk_queue[j]) < min)
            {
                min = abs(head - disk_queue[j]);
                min_index = j;
            }
        }
        seek_time += min;
        head = disk_queue[min_index];
        disk_queue[min_index] = -1;
        printf("%d ", head);
    }

    printf("\nSeek time: %d\n", seek_time);

    return 0;
}
