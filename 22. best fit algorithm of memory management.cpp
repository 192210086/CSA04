#include <stdio.h>

int main() {
  // Declare the variables
  int memory_size, process_size, number_of_processes, i, j;
  int *memory_blocks, *processes;

  // Get the memory size
  printf("Enter the memory size: ");
  scanf("%d", &memory_size);

  // Get the number of processes
  printf("Enter the number of processes: ");
  scanf("%d", &number_of_processes);

  // Allocate memory for the memory blocks and processes
  memory_blocks = (int *)malloc(memory_size * sizeof(int));
  processes = (int *)malloc(number_of_processes * sizeof(int));

  // Get the sizes of the processes
  for (i = 0; i < number_of_processes; i++) {
    printf("Enter the size of process %d: ", i + 1);
    scanf("%d", &processes[i]);
  }

  // Initialize the memory blocks as free
  for (i = 0; i < memory_size; i++) {
    memory_blocks[i] = 0;
  }

  // Implement the best fit algorithm
  for (i = 0; i < number_of_processes; i++) {
    // Find the best fit memory block for the process
    int best_fit_index = -1;
    int best_fit_size = -1;
    for (j = 0; j < memory_size; j++) {
      if (memory_blocks[j] >= processes[i] && (best_fit_size == -1 || memory_blocks[j] < best_fit_size)) {
        best_fit_index = j;
        best_fit_size = memory_blocks[j];
      }
    }

    // If a best fit memory block was found, allocate it to the process
    if (best_fit_index != -1) {
      memory_blocks[best_fit_index] -= processes[i];
      printf("Process %d allocated to memory block %d\n", i + 1, best_fit_index + 1);
    } else {
      printf("Process %d cannot be allocated to memory\n", i + 1);
    }
  }

  // Free the memory allocated for the memory blocks and processes
  free(memory_blocks);
  free(processes);

  return 0;
}
