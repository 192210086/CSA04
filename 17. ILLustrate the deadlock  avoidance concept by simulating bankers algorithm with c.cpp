#include <stdio.h>

// Define the number of processes and resources
#define PROCESSES 5
#define RESOURCES 3

// Define the data structures
int Available[RESOURCES];
int Max[PROCESSES][RESOURCES];
int Allocation[PROCESSES][RESOURCES];
int Need[PROCESSES][RESOURCES];

// Initialize the data structures
void init() {
  for (int i = 0; i < RESOURCES; i++) {
    Available[i] = 10;
  }

  for (int i = 0; i < PROCESSES; i++) {
    for (int j = 0; j < RESOURCES; j++) {
      Max[i][j] = 5;
      Allocation[i][j] = 0;
      Need[i][j] = Max[i][j] - Allocation[i][j];
    }
  }
}

// Check if the system is in a safe state
int isSafe() {
  for (int i = 0; i < PROCESSES; i++) {
    int found = 0;
    for (int j = 0; j < RESOURCES; j++) {
      if (Need[i][j] > Available[j]) {
        found = 1;
        break;
      }
    }

    if (found == 0) {
      return 1;
    }
  }

  return 0;
}

// Request resources for a process
void request(int process, int resources[]) {
  for (int i = 0; i < RESOURCES; i++) {
    Available[i] -= resources[i];
    Allocation[process][i] += resources[i];
    Need[process][i] -= resources[i];
  }
}

// Release resources for a process
void release(int process, int resources[]) {
  for (int i = 0; i < RESOURCES; i++) {
    Available[i] += resources[i];
    Allocation[process][i] -= resources[i];
    Need[process][i] += resources[i];
  }
}

// Main function
int main() {
  init();

  // Process 0 requests 3 resources
  int resources0[] = {3, 2, 1};
  request(0, resources0);

  // Process 1 requests 2 resources
  int resources1[] = {2, 1, 0};
  request(1, resources1);

  // Process 2 requests 1 resource
  int resources2[] = {1, 0, 0};
  request(2, resources2);

  // Check if the system is in a safe state
  if (isSafe()) {
    printf("The system is in a safe state.\n");
  } else {
    printf("The system is in a deadlock state.\n");
  }

  // Release resources for process 0
  release(0, resources0);

  // Release resources for process 1
  release(1, resources1);

  // Release resources for process 2
  release(2, resources2);

  return 0;
}
