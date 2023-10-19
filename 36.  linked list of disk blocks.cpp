#include <stdio.h>

// Structure to represent a disk block
struct disk_block {
  int data;
  int next_block;
};

// Structure to represent a file
struct file {
  int start_block;
  int end_block;
};

// Function to create a new file
void create_file(struct file *file) {
  // Initialize the file
  file->start_block = -1;
  file->end_block = -1;

  // Allocate a new disk block for the file
  int disk_block = allocate_disk_block();

  // Set the file's start block to the new disk block
  file->start_block = disk_block;

  // Set the file's end block to the new disk block
  file->end_block = disk_block;

  // Write the file to disk
  write_file(file);
}

// Function to write a file to disk
void write_file(struct file *file) {
  // Open the file for writing
  FILE *fp = fopen("file.txt", "w");

  // Write the file's start block to the file
  fprintf(fp, "%d\n", file->start_block);

  // Write the file's end block to the file
  fprintf(fp, "%d\n", file->end_block);

  // Close the file
  fclose(fp);
}

// Function to allocate a new disk block
int allocate_disk_block() {
  // Open the disk for writing
  FILE *fp = fopen("disk.txt", "w");

  // Write a new disk block to the disk
  fprintf(fp, "%d\n", 0);

  // Close the file
  fclose(fp);

  // Return the new disk block
  return 0;
}

// Function to read a file from disk
void read_file(struct file *file) {
  // Open the file for reading
  FILE *fp = fopen("file.txt", "r");

  // Read the file's start block from the file
  fscanf(fp, "%d", &file->start_block);

  // Read the file's end block from the file
  fscanf(fp, "%d", &file->end_block);

  // Close the file
  fclose(fp);

  // Read the file from disk
  int i;
  for (i = file->start_block; i <= file->end_block; i++) {
    // Read the disk block
    int data;
    FILE *fp = fopen("disk.txt", "r");
    fscanf(fp, "%d", &data);
    fclose(fp);

    // Print the data
    printf("%d\n", data);
  }
}

// Main function
int main() {
  // Create a new file
  struct file file;
  create_file(&file);

  // Write some data to the file
  int i;
  for (i = 0; i < 10; i++) {
    file.data[i] = i;
  }

  // Write the file to disk
  write_file(&file);

  // Read the file from disk
  read_file(&file);

  return 0;
}
