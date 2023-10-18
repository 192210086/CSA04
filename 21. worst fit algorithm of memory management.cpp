#include <stdio.h>

int main() {
  int n, m;
  int process[100], memory[100];

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  printf("Enter the number of memory blocks: ");
  scanf("%d", &m);

  for (int i = 0; i < n; i++) {
    printf("Enter the size of process %d: ", i + 1);
    scanf("%d", &process[i]);
  }

  for (int i = 0; i < m; i++) {
    printf("Enter the size of memory block %d: ", i + 1);
    scanf("%d", &memory[i]);
  }

  for (int i = 0; i < n; i++) {
    int best = -1;
    for (int j = 0; j < m; j++) {
      if (memory[j] >= process[i] && memory[j] > best) {
        best = j;
      }
    }
    if (best != -1) {
      memory[best] -= process[i];
      printf("Process %d is allocated to memory block %d.\n", i + 1, best + 1);
    } else {
      printf("Process %d cannot be allocated to any memory block.\n", i + 1);
    }
  }

  return 0;
}
