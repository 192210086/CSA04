#include <stdio.h>

int main() {
  int n, i, head, total_head_movement = 0;
  int *req;

  // Get the number of requests
  printf("Enter the number of requests: ");
  scanf("%d", &n);

  // Allocate memory for the requests array
  req = (int *)malloc(n * sizeof(int));

  // Get the requests
  for (i = 0; i < n; i++) {
    printf("Enter the request %d: ", i + 1);
    scanf("%d", &req[i]);
  }

  // Get the initial position of the disk head
  printf("Enter the initial position of the disk head: ");
  scanf("%d", &head);

  // Calculate the total head movement
  for (i = 0; i < n; i++) {
    total_head_movement += abs(head - req[i]);
    head = req[i];
  }

  // Print the total head movement
  printf("The total head movement is: %d\n", total_head_movement);

  return 0;
}
