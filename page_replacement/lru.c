#include <stdio.h>

int main()
{
    int f = 0, p = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the number of pages: ");
    scanf("%d", &p);

    int frames[f], reference_string[p];

    printf("Enter the reference string: ");
    for (int i = 0; i < p; i++)
        scanf("%d", &reference_string[i]);

    for (int i = 0; i < f; i++)
        frames[i] = -1;

    int hit = 0, miss = 0, flag = 0;

    for (int i = 0; i < p; i++)
    {
        flag = 0;
        for (int k = 0; k < f; k++)
        {
            if (frames[k] == reference_string[i])
            {
                flag = 1;
                hit++;
                break;
            }
        }
        if (flag == 0)
        {
            int min = 0, min_index = 0;
            for (int k = 0; k < f; k++)
            {
                int temp = 0;
                for (int l = i + 1; l < p; l++)
                {
                    if (frames[k] == reference_string[l])
                    {
                        temp = l;
                        break;
                    }
                }
                if (temp == 0)
                {
                    min_index = k;
                    break;
                }
                else if (temp > min)
                {
                    min = temp;
                    min_index = k;
                }
            }
            frames[min_index] = reference_string[i];
            miss++;
        }
        printf("Page frame: ");
        for (int k = 0; k < f; k++)
            printf("%d ", frames[k]);
        printf("\n");
    }
    printf("Number of hits: %d\n", hit);
    printf("Number of misses: %d\n", miss);
    printf("Hit ratio: %f\n", (float)hit / (float)p);
    printf("Miss ratio: %f\n", (float)miss / (float)p);

    return 0;
}