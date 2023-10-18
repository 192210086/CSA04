#include <stdio.h>

int main() {
  int n, i, j, burst_time[100], arrival_time[100], wait_time[100], turnaround_time[100];
  float average_wait_time, average_turnaround_time;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter the arrival time of process %d: ", i + 1);
    scanf("%d", &arrival_time[i]);
    printf("Enter the burst time of process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
  }

  // Sort the processes according to their arrival time
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arrival_time[i] > arrival_time[j]) {
        int temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;

        int temp2 = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp2;
      }
    }
  }

  // Calculate the waiting time for each process
  wait_time[0] = 0;
  for (i = 1; i < n; i++) {
    wait_time[i] = arrival_time[i] - arrival_time[i - 1] + burst_time[i - 1];
  }

  // Calculate the turnaround time for each process
  turnaround_time[0] = burst_time[0];
  for (i = 1; i < n; i++) {
    turnaround_time[i] = burst_time[i] + wait_time[i];
  }

  // Calculate the average waiting time
  average_wait_time = 0;
  for (i = 0; i < n; i++) {
    average_wait_time += wait_time[i];
  }
  average_wait_time /= n;

  // Calculate the average turnaround time
  average_turnaround_time = 0;
  for (i = 0; i < n; i++) {
    average_turnaround_time += turnaround_time[i];
  }
  average_turnaround_time /= n;

  // Print the results
  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
  for (i = 0; i < n; i++) {
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, arrival_time[i], burst_time[i], wait_time[i], turnaround_time[i]);
  }

  printf("\nAverage waiting time: %.2f", average_wait_time);
  printf("\nAverage turnaround time: %.2f", average_turnaround_time);

  return 0;
}
