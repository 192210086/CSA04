#include <stdio.h>
#include <semaphore.h>

int main() {
  // Semaphores
  sem_t read_count;
  sem_t write;

  // Initialize semaphores
  sem_init(&read_count, 0, 1);
  sem_init(&write, 0, 1);

  // Reader process
  int reader() {
    // Acquire read lock
    sem_wait(&read_count);

    // Read data
    printf("Reader is reading...\n");

    // Release read lock
    sem_post(&read_count);
  }

  // Writer process
  int writer() {
    // Acquire write lock
    sem_wait(&write);

    // Write data
    printf("Writer is writing...\n");

    // Release write lock
    sem_post(&write);
  }

  // Create reader and writer threads
  pthread_t reader_thread;
  pthread_t writer_thread;

  pthread_create(&reader_thread, NULL, reader, NULL);
  pthread_create(&writer_thread, NULL, writer, NULL);

  // Join reader and writer threads
  pthread_join(reader_thread, NULL);
  pthread_join(writer_thread, NULL);

  return 0;
}

