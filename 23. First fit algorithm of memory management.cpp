#include <stdio.h>

int main() {
  // Initialize the memory blocks.
  int memory[] = {100, 50, 20, 10};
  int n = sizeof(memory) / sizeof(memory[0]);

  // Get the number of processes.
  int processes;
  printf("Enter the number of processes: ");
  scanf("%d", &processes);

  // Get the size of each process.
  int sizes[processes];
  for (int i = 0; i < processes; i++) {
    printf("Enter the size of process %d: ", i + 1);
    scanf("%d", &sizes[i]);
  }

  // Allocate the processes to the memory blocks.
  for (int i = 0; i < processes; i++) {
    int found = 0;
    for (int j = 0; j < n; j++) {
      if (memory[j] >= sizes[i]) {
        memory[j] -= sizes[i];
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("Process %d could not be allocated memory.\n", i + 1);
    }
  }

  // Print the memory blocks.
  printf("Memory blocks:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", memory[i]);
  }
  printf("\n");

  return 0;
}
