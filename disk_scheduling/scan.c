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

    int total_head_movement = 0;
    int direction = 1;
    int requests_serviced = 0;
    for (int i = head; i < 200; i += direction)
    {
        if (i == 199)
        {
            direction = -1;
            total_head_movement += abs(head - 199);
            head = 199;
            printf("%d ", head);
        }

        for (int j = 0; j < p; j++)
        {
            if (disk_queue[j] == i)
            {
                total_head_movement += abs(head - disk_queue[j]);
                head = disk_queue[j];
                disk_queue[j] = -1;
                requests_serviced++;
                printf("%d ", head);
            }
        }

        if (requests_serviced == p)
            break;
    }

    printf("\nTotal head movement: %d\n", total_head_movement);

    return 0;
}
