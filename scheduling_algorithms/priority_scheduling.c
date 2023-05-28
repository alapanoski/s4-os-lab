#include <stdio.h>

typedef struct
{
    int pid;
    int p;
    int at;
    int bt;
    int ct;
    int rt;
    int wt;
    int tat;
} process;

int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    process a[n];

    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        scanf("%d %d %d", &a[i].at, &a[i].bt, &a[i].p);
        a[i].rt = a[i].bt;
        a[i].wt = 0;
    }

    int completed = 0;
    int twt = 0, ttat = 0, current_time = 0;
    int time_quantum = 1; // Assuming time quantum of 1 unit

    while (completed < n)
    {
        int selected = -1;
        int highest_priority = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i].at <= current_time && a[i].rt > 0)
            {
                if (highest_priority == -1 || a[i].p > highest_priority)
                {
                    highest_priority = a[i].p;
                    selected = i;
                }
            }
        }

        if (selected == -1)
        {
            current_time++;
            continue;
        }

        a[selected].rt--;

        if (a[selected].rt == 0)
        {
            a[selected].ct = current_time + 1;
            a[selected].tat = a[selected].ct - a[selected].at;
            a[selected].wt = a[selected].tat - a[selected].bt;

            twt += a[selected].wt;
            ttat += a[selected].tat;

            completed++;
        }

        current_time++;
    }

    int avg_tat = ttat / n;
    int avg_wt = twt / n;

    printf("PID\tBurst\tArrival\tPriority\tCompletion\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", a[i].pid, a[i].bt, a[i].at, a[i].p, a[i].ct, a[i].wt, a[i].tat);

    printf("Total Turnaround Time: %d\n", ttat);
    printf("Total Waiting Time: %d\n", twt);

    printf("Average Turnaround Time: %d\n", avg_tat);
    printf("Average Waiting Time: %d\n", avg_wt);

    return 0;
}
