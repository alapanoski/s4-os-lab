#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

char *buffer[BUFFER_SIZE];
sem_t empty, full;
int in = 0, out = 0;

void *producer(void *arg)
{
    char *item;
    while (1)
    {
        item = malloc(100 * sizeof(char));

        printf("Enter a string to add to the buffer: ");
        fgets(item, 100, stdin);

        sem_wait(&empty);

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&full);

        printf("Produced item: %s\n", item);
    }
}

void *consumer(void *arg)
{
    char *item;
    while (1)
    {
        sem_wait(&full);

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&empty);

        printf("\nConsumed item: %s\n", item);

        free(item);
    }
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
