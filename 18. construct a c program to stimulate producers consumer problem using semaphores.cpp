#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t full;
sem_t empty;

void producer() {
  int item;

  while (1) {
    // Generate an item
    item = rand() % 100;

    // Wait for the buffer to have space
    sem_wait(&empty);

    // Add the item to the buffer
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;

    // Release the buffer
    sem_post(&full);
  }
}

void consumer() {
  int item;

  while (1) {
    // Wait for the buffer to have data
    sem_wait(&full);

    // Remove the item from the buffer
    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    // Consume the item
    printf("Consumed item: %d\n", item);

    // Release the buffer
    sem_post(&empty);
  }
}

int main() {
  // Initialize the semaphores
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, BUFFER_SIZE);

  // Create the producer and consumer threads
  pthread_t producer_thread;
  pthread_t consumer_thread;

  pthread_create(&producer_thread, NULL, (void *)producer, NULL);
  pthread_create(&consumer_thread, NULL, (void *)consumer, NULL);

  // Join the producer and consumer threads
  pthread_join(producer_thread, NULL);
  pthread_join(consumer_thread, NULL);

  return 0;
}
