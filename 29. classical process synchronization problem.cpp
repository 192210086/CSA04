#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // Create two semaphores, one for the producer and one for the consumer.
  int semaphore_producer = sem_open("semaphore_producer", 0, 0);
  int semaphore_consumer = sem_open("semaphore_consumer", 0, 0);

  // Create two processes, one for the producer and one for the consumer.
  int pid_producer = fork();
  if (pid_producer == 0) {
    // Producer process.
    while (1) {
      // Produce an item.
      printf("Producer produced an item.\n");

      // Sleep for a random amount of time.
      usleep(rand() % 1000000);

      // Signal the consumer that there is an item available.
      sem_post(semaphore_consumer);
    }
  } else {
    // Consumer process.
    while (1) {
      // Wait for the producer to produce an item.
      sem_wait(semaphore_producer);

      // Consume the item.
      printf("Consumer consumed an item.\n");

      // Sleep for a random amount of time.
      usleep(rand() % 1000000);

      // Signal the producer that the item has been consumed.
      sem_post(semaphore_producer);
    }
  }

  return 0;
}

