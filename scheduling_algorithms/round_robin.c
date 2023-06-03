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
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process a[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        scanf("%d %d", &a[i].at, &a[i].bt);
        a[i].rt = a[i].bt;
    }

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].at > a[j + 1].at)
            {
                process temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int completed = 0;
    int twt = 0, ttat = 0, current_time = 0;
    process q[n];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++)
        q[++rear] = a[i];

    while (completed < n)
    {
        int idx = front % n;

        if (q[idx].rt <= quantum)
        {
            current_time += q[idx].rt;
            q[idx].ct = current_time;
            q[idx].tat = q[idx].ct - q[idx].at;
            q[idx].wt = q[idx].tat - q[idx].bt;
            twt += q[idx].wt;
            ttat += q[idx].tat;
            q[idx].rt = 0;
            completed++;
        }
        else
        {
            current_time += quantum;
            q[idx].rt -= quantum;
        }

        front++;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = q[i];
    }

    int avg_tat = ttat / n;
    int avg_wt = twt / n;

    printf("\nPID\tArrival\tBurst\tCompletion\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", a[i].pid, a[i].at, a[i].bt, a[i].ct, a[i].wt, a[i].tat);
    }

    printf("\nTotal Turnaround Time: %d\n", ttat);
    printf("Total Waiting Time: %d\n", twt);

    printf("Average Turnaround Time: %d\n", avg_tat);
    printf("Average Waiting Time: %d\n", avg_wt);

    return 0;
}
