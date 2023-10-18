#include <stdio.h>

int main() {
  // Declare the size of the memory.
  int size;
  printf("Enter the size of the memory: ");
  scanf("%d", &size);

  // Declare the number of pages to be inserted.
  int num_pages;
  printf("Enter the number of pages to be inserted: ");
  scanf("%d", &num_pages);

  // Declare the array of pages.
  int pages[num_pages];

  // Declare the stack of pages.
  int stack[size];
  int top = -1;

  // Get the pages to be inserted.
  for (int i = 0; i < num_pages; i++) {
    printf("Enter the page %d: ", i + 1);
    scanf("%d", &pages[i]);
  }

  // Insert the pages into the memory.
  for (int i = 0; i < num_pages; i++) {
    // If the stack is full, remove the least recently used page.
    if (top == size - 1) {
      int least_recently_used = -1;
      for (int j = 0; j < size; j++) {
        if (stack[j] < least_recently_used) {
          least_recently_used = j;
        }
      }
      stack[least_recently_used] = pages[i];
    } else {
      top++;
      stack[top] = pages[i];
    }
  }

  // Print the pages in the memory.
  printf("The pages in the memory are: ");
  for (int i = 0; i < size; i++) {
    if (stack[i] != -1) {
      printf("%d ", stack[i]);
    }
  }
  printf("\n");

  // Print the pages that are not in the memory.
  printf("The pages that are not in the memory are: ");
  for (int i = 0; i < num_pages; i++) {
    int found = 0;
    for (int j = 0; j < size; j++) {
      if (stack[j] == pages[i]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("%d ", pages[i]);
    }
  }
  printf("\n");

  return 0;
}
