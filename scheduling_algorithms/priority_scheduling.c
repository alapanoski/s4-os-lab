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

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].p < a[j + 1].p)
            {
                process temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (current_time < a[i].at)
            current_time = a[i].at;

        a[i].ct = current_time + a[i].bt;
        a[i].tat = a[i].ct - a[i].at;
        a[i].wt = a[i].tat - a[i].bt;

        twt += a[i].wt;
        ttat += a[i].tat;

        current_time = a[i].ct;
    }

    int avg_tat = ttat / n;
    int avg_wt = twt / n;

    printf("PID\tBurst\tArrival\tPriority\tCompletion\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", a[i].pid, a[i].bt, a[i].at, a[i].p, a[i].ct, a[i].wt, a[i].tat);

    printf("Total Turn Around Time: %d\n", ttat);
    printf("Total Waiting Time: %d\n", twt);

    printf("Average Turn Around Time: %d\n", avg_tat);
    printf("Average Waiting Time: %d\n", avg_wt);

    return 0;
}