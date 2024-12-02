#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;
int empty = BUFFER_SIZE;
int full = 0;
int mutex = 1;

void wait(int *semaphore, char *k)
{
    int count = 0;
    while (*semaphore <= 0)
    {
        if (count == 0)
            printf("%s", k);
        count = 1;
    }
    --(*semaphore);
}

void signal(int *semaphore)
{
    ++(*semaphore);
}

void *producer()
{
    char *waitMsg = "Producer waiting for empty slot...\n";
    while (1)
    {
        wait(&empty, waitMsg);
        wait(&mutex, "");

        int item = rand() % 100;
        buffer[count] = item;
        count = (count + 1) % BUFFER_SIZE;
        printf("Producer produces item: %d\n", item);

        signal(&mutex);
        signal(&full);
        sleep(rand() % 4);
    }
}

void *consumer()
{
    char *waitMsg = "Consumer waiting for filled slot...\n";
    while (1)
    {
        wait(&full, waitMsg);
        wait(&mutex, "");

        int item = buffer[--count];
        printf("Consumer consumes item: %d\n", item);

        signal(&mutex);
        signal(&empty);
        sleep(rand() % 4);
    }
}

int main()
{
    srand(time(0));
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}