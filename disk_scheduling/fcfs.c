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
    for (int i = 0; i < p; i++)
    {
        total_head_movement += abs(head - disk_queue[i]);
        head = disk_queue[i];
        printf("%d ", head);
    }

    printf("\nTotal head movement: %d\n", total_head_movement);

    return 0;
}