#include <stdio.h>

struct disk {
  int size;
  int *blocks;
};

struct file {
  char *name;
  int start_block;
  int size;
};

void init_disk(struct disk *d, int size) {
  d->size = size;
  d->blocks = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    d->blocks[i] = -1;
  }
}

struct file *allocate_file(struct disk *d, char *name, int size) {
  // Find a contiguous block of size `size`
  int start_block = -1;
  for (int i = 0; i < d->size - size + 1; i++) {
    if (d->blocks[i] == -1 && d->blocks[i + size - 1] == -1) {
      start_block = i;
      break;
    }
  }

  // If no contiguous block of size `size` was found, return NULL
  if (start_block == -1) {
    return NULL;
  }

  // Allocate the block to the file
  for (int i = 0; i < size; i++) {
    d->blocks[start_block + i] = i;
  }

  // Create a new file struct and return it
  struct file *f = malloc(sizeof(struct file));
  f->name = name;
  f->start_block = start_block;
  f->size = size;
  return f;
}

void free_file(struct disk *d, struct file *f) {
  // Deallocate the blocks from the file
  for (int i = 0; i < f->size; i++) {
    d->blocks[f->start_block + i] = -1;
  }
}

int main() {
  // Create a disk with 100 blocks
  struct disk d;
  init_disk(&d, 100);

  // Allocate a file of size 10
  struct file *f1 = allocate_file(&d, "file1", 10);
  if (f1 == NULL) {
    printf("Could not allocate file1\n");
    return 1;
  }

  // Allocate a file of size 5
  struct file *f2 = allocate_file(&d, "file2", 5);
  if (f2 == NULL) {
    printf("Could not allocate file2\n");
    return 1;
  }

  // Free the first file
  free_file(&d, f1);

  // Allocate a file of size 6
  struct file *f3 = allocate_file(&d, "file3", 6);
  if (f3 == NULL) {
    printf("Could not allocate file3\n");
    return 1;
  }

  // Print the contents of the disk
  for (int i = 0; i < d.size; i++) {
    printf("%d ", d.blocks[i]);
  }
  printf("\n");

  return 0;
}
