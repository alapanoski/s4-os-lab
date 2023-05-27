#include <stdio.h>

typedef struct
{
    int pid;
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

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        scanf("%d %d", &a[i].at, &a[i].bt);
    }

    int completed = 0;
    int twt = 0, ttat = 0, current_time = 0;

    for (int i = 0; i < n; i++)
    {
        a[i].rt = a[i].bt;
        a[i].wt = 0;
    }

    while (completed < n)
    {
        int shortest_job = -1;
        int shortest_time = 99999;

        for (int i = 0; i < n; i++)
        {
            if (a[i].at <= current_time && a[i].rt < shortest_time && a[i].rt > 0)
            {
                shortest_job = i;
                shortest_time = a[i].rt;
            }

            if (shortest_job == -1)
                current_time++;

            else
            {
                a[shortest_job].rt--;
                current_time++;
                if (a[shortest_job].rt == 0)
                {
                    completed++;
                    a[shortest_job].ct = current_time;
                    a[shortest_job].tat = a[shortest_job].ct - a[shortest_job].at;
                    a[shortest_job].wt = a[shortest_job].tat - a[shortest_job].bt;
                    twt += a[shortest_job].wt;
                    ttat += a[shortest_job].tat;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i].wt = a[i].tat - a[i].bt;
        twt += a[i].wt;
        ttat += a[i].tat;
    }

    int avg_tat = ttat / n;
    int avg_wt = twt / n;

    printf("PID\tBurst\tArrival\tCompletion\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", a[i].pid, a[i].bt, a[i].at, a[i].ct, a[i].wt, a[i].tat);

    printf("Total Turn Around Time: %d\n", ttat);
    printf("Total Waiting Time: %d\n", twt);

    printf("Average Turn Around Time: %d\n", avg_tat);
    printf("Average Waiting Time: %d\n", avg_wt);

    return 0;
}