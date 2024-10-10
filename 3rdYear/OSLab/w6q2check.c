#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
// producer consumer problem
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;
int empty = BUFFER_SIZE;
int full = 0;
int mutex = 1;

void wait(int *semaphore)
{
    while (*semaphore <= 0);
    --(*semaphore);
}

void signal(int *semaphore)
{
    ++(*semaphore);
}

void *producer()
{
    while (1)
    {
        wait(&empty);
        wait(&mutex);

        int item = rand() % 100;
        buffer[count] = item;
        count = (count + 1) % BUFFER_SIZE;
        printf("Producer produces item: %d\n", item);

        signal(&mutex);
        signal(&full);
        sleep(2);
    }
}

void *consumer()
{
    while (1)
    {
        wait(&full);
        wait(&mutex);

        int item = buffer[--count];
        printf("Consumer consumes item: %d\n", item);

        signal(&mutex);
        signal(&empty);
        sleep(2);
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