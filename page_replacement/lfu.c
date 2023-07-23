#include <stdio.h>

int main()
{
    int f = 0, p = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the number of pages: ");
    scanf("%d", &p);

    int frames[f], reference_string[p], frequency[f];

    printf("Enter the reference string: ");
    for (int i = 0; i < p; i++)
        scanf("%d", &reference_string[i]);

    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
        frequency[i] = 0;
    }

    int hit = 0, miss = 0;

    for (int i = 0; i < p; i++)
    {
        int page = reference_string[i];
        int flag = 0;

        for (int k = 0; k < f; k++)
        {
            if (frames[k] == page)
            {
                flag = 1;
                hit++;
                frequency[k]++;
                break;
            }
        }

        if (flag == 0)
        {
            int min_frequency = frequency[0];
            int min_frequency_index = 0;

            for (int k = 1; k < f; k++)
            {
                if (frequency[k] < min_frequency)
                {
                    min_frequency = frequency[k];
                    min_frequency_index = k;
                }
            }

            frames[min_frequency_index] = page;
            frequency[min_frequency_index] = 1;
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
