#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char *filename, *pattern;
  int line_number = 1;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <filename> <pattern>\n", argv[0]);
    return 1;
  }

  filename = argv[1];
  pattern = argv[2];

  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open file %s\n", filename);
    return 1;
  }

  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, pattern)) {
      printf("%d: %s", line_number, line);
      line_number++;
    }
  }

  fclose(fp);

  return 0;
}
