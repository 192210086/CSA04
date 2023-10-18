#include <stdio.h>

int main() {
  // Declare the necessary variables.
  int frames, pages, page_faults, *frames_list, *pages_list;

  // Get the number of frames from the user.
  printf("Enter the number of frames: ");
  scanf("%d", &frames);

  // Get the number of pages from the user.
  printf("Enter the number of pages: ");
  scanf("%d", &pages);

  // Initialize the frames list.
  frames_list = (int *)malloc(sizeof(int) * frames);
  for (int i = 0; i < frames; i++) {
    frames_list[i] = -1;
  }

  // Initialize the pages list.
  pages_list = (int *)malloc(sizeof(int) * pages);
  for (int i = 0; i < pages; i++) {
    pages_list[i] = i;
  }

  // Initialize the page faults counter.
  page_faults = 0;

  // Start the paging process.
  for (int i = 0; i < pages; i++) {
    // Check if the page is already in memory.
    int found = 0;
    for (int j = 0; j < frames; j++) {
      if (frames_list[j] == pages_list[i]) {
        found = 1;
        break;
      }
    }

    // If the page is not in memory, then replace the oldest page in memory with the new page.
    if (!found) {
      frames_list[page_faults] = pages_list[i];
      page_faults++;
    }
  }

  // Print the number of page faults.
  printf("The number of page faults is: %d\n", page_faults);

  // Free the memory allocated for the frames list and the pages list.
  free(frames_list);
  free(pages_list);

  return 0;
}

