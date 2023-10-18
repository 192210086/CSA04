#include <stdio.h>
#include <pthread.h>

void *my_thread(void *arg) {
  printf("Hello from thread!\n");
  pthread_exit(NULL);
  return NULL;
}

int main() {
  pthread_t thread;
  int rc;

  rc = pthread_create(&thread, NULL, my_thread, NULL);
  if (rc != 0) {
    printf("Error creating thread!\n");
    return 1;
  }

  pthread_join(thread, NULL);
  return 0;
}
