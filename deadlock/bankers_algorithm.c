#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], available[m], work[m], finish[n];

    printf("Enter the allocation matrix: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the max matrix: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available matrix: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    for (int i = 0; i < n; i++)
        finish[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    for (int i = 0; i < m; i++)
        work[i] = available[i];

    int flag = 0, count = 0;

    while (count < n)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[i][k];
                    finish[i] = 1;
                    flag = 1;
                    count++;
                }
            }
        }
        if (flag == 0)
            break;
    }

    if (count == n)
        printf("Safe state\n");
    else
        printf("Unsafe state\n");

    return 0;
}
