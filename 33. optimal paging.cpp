#include <stdio.h>

int main() {
  int memory_size, page_size, number_of_processes, number_of_pages[100], page_table[100][100];
  int i, j, k, process, page, frame;

  printf("Enter memory size: ");
  scanf("%d", &memory_size);

  printf("Enter page size: ");
  scanf("%d", &page_size);

  printf("Enter number of processes: ");
  scanf("%d", &number_of_processes);

  for (i = 0; i < number_of_processes; i++) {
    printf("Enter number of pages for process %d: ", i + 1);
    scanf("%d", &number_of_pages[i]);

    for (j = 0; j < number_of_pages[i]; j++) {
      printf("Enter page table entry for process %d, page %d: ", i + 1, j + 1);
      scanf("%d", &page_table[i][j]);
    }
  }

  // Initialize the frame table.
  int frame_table[memory_size];
  for (i = 0; i < memory_size; i++) {
    frame_table[i] = -1;
  }

  // Initialize the page fault counter.
  int page_fault_count = 0;

  // Loop over all the processes.
  for (i = 0; i < number_of_processes; i++) {
    // Loop over all the pages for the process.
    for (j = 0; j < number_of_pages[i]; j++) {
      // Check if the page is already in memory.
      int page_in_memory = 0;
      for (k = 0; k < memory_size; k++) {
        if (frame_table[k] == page_table[i][j]) {
          page_in_memory = 1;
          break;
        }
      }

      // If the page is not in memory, then we need to find a free frame.
      if (!page_in_memory) {
        // Loop over all the frames to find a free frame.
        for (k = 0; k < memory_size; k++) {
          if (frame_table[k] == -1) {
            frame_table[k] = page_table[i][j];
            break;
          }
        }

        // If we couldn't find a free frame, then we need to evict a page.
        if (k == memory_size) {
          // Choose the page to evict using the optimal algorithm.
          int optimal_page = -1;
          int max_distance = -1;
          for (k = 0; k < memory_size; k++) {
            int distance = 0;
            for (j = 0; j < number_of_processes; j++) {
              for (l = 0; l < number_of_pages[j]; l++) {
                if (frame_table[k] == page_table[j][l]) {
                  distance = i - j;
                  break;
                }
              }
              if (distance > max_distance) {
                max_distance = distance;
                optimal_page = k;
              }
            }
          }

          // Evict the page.
          frame_table[optimal_page] = page_table[i][j];
        }
      }

      // Increment the page fault counter.
      page_fault_count++;
    }
  }

  // Print the number of page faults.
  printf("Number of page faults: %d\n", page_fault_count);

  return 0;
}
