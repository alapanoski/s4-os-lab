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

    printf("Enter arrival time, burst time and priority for each process:\n");
    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        scanf("%d %d %d", &a[i].at, &a[i].bt, &a[i].p);
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
        int top_job = -1;
        int top_priority = 99999;

        for (int i = 0; i < n; i++)
        {
            if (a[i].at <= current_time && a[i].p < top_priority && a[i].rt > 0)
            {
                top_job = i;
                top_priority = a[i].p;
            }
        }

        if (top_job == -1)
            current_time++;
        else
        {
            a[top_job].rt--;
            current_time++;
            if (a[top_job].rt == 0)
            {
                completed++;
                a[top_job].ct = current_time;
                a[top_job].tat = a[top_job].ct - a[top_job].at;
                a[top_job].wt = a[top_job].tat - a[top_job].bt;
                twt += a[top_job].wt;
                ttat += a[top_job].tat;
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

    printf("PID\tBurst\tArrrival\tPriority\tCompletion\tWait\tTurn Aruund\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].bt, a[i].at, a[i].p, a[i].ct, a[i].wt, a[i].tat);

    printf("Total Turn Around Time: %d\n", ttat);
    printf("Total Waiting Time: %d\n", twt);

    printf("Average Turn Around Time: %d\n", avg_tat);
    printf("Average Waiting Time: %d\n", avg_wt);

    return 0;
}