#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
  // Create a new file.
  int fd = open("new_file", O_CREAT | O_WRONLY, 0644);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  // Write some data to the file.
  char *data = "Hello, world!";
  size_t n = write(fd, data, strlen(data));
  if (n < 0) {
    perror("write");
    return 1;
  }

  // Close the file.
  close(fd);

  // Open the file for reading.
  fd = open("new_file", O_RDONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  // Read the data from the file.
  char buffer[1024];
  n = read(fd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Print the data to stdout.
  printf("%s\n", buffer);

  // Close the file.
  close(fd);

  return 0;
}
