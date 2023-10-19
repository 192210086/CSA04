#include <stdio.h>

void main() {
  int n, h, tot, *t, *d, *atr;
  int i, j, p, sum;

  printf("Enter the number of tracks to be traversed: ");
  scanf("%d", &n);

  printf("Enter the position of the head: ");
  scanf("%d", &h);

  t = (int *)malloc((n + 3) * sizeof(int));
  d = (int *)malloc((n + 3) * sizeof(int));
  atr = (int *)malloc((n + 3) * sizeof(int));

  t[0] = 0;
  t[1] = h;
  t[2] = tot - 1;

  printf("Enter the total tracks: ");
  scanf("%d", &tot);

  for (i = 3; i <= n + 2; i++) {
    scanf("%d", &t[i]);
  }

  for (i = 0; i <= n + 2; i++) {
    for (j = 0; j < (n + 2) - i - 1; j++) {
      if (t[j] > t[j + 1]) {
        temp = t[j];
        t[j] = t[j + 1];
        t[j + 1] = temp;
      }
    }
  }

  p = 0;
  sum = 0;

  while (p != (n + 3) && t[i] != t[h]) {
    atr[p] = t[i];
    p++;
    i++;
    sum += abs(t[i] - h);
  }

  while (p != (n + 3)) {
    atr[p] = t[i];
    p++;
    i--;
    sum += abs(t[i] - h);
  }

  printf("The total distance traveled is: %d\n", sum);

  for (i = 0; i < n + 3; i++) {
    printf("%d ", t[i]);
  }

  printf("\n");

  for (i = 0; i < n + 3; i++) {
    printf("%d ", d[i]);
  }

  printf("\n");

  for (i = 0; i < n + 3; i++) {
    printf("%d ", atr[i]);
  }

  printf("\n");

  free(t);
  free(d);
  free(atr);
}
