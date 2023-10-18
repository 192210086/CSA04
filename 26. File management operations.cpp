#include <stdio.h>

int main() {
  FILE *fp;
  char ch;

  // Open the file for reading.
  fp = fopen("test.txt", "r");

  // Check if the file exists.
  if (fp == NULL) {
    printf("File does not exist.\n");
    return 1;
  }

  // Read the file character by character.
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  // Close the file.
  fclose(fp);

  return 0;
}
