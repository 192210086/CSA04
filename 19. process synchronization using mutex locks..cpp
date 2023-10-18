#include <pthread.h>

int main() {
  pthread_mutex_t mutex;

  pthread_mutex_init(&mutex, NULL);

  // Create two threads.
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, &func1, &mutex);
  pthread_create(&thread2, NULL, &func2, &mutex);

  // Wait for both threads to finish.
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // Destroy the mutex.
  pthread_mutex_destroy(&mutex);

  return 0;
}

void func1(void *arg) {
  pthread_mutex_lock((pthread_mutex_t *)arg);

  // Do something that needs to be synchronized.

  pthread_mutex_unlock((pthread_mutex_t *)arg);
}

void func2(void *arg) {
  pthread_mutex_lock((pthread_mutex_t *)arg);

  // Do something that needs to be synchronized.

  pthread_mutex_unlock((pthread_mutex_t *)arg);
}
