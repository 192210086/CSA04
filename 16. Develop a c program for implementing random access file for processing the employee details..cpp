#include <stdio.h>
#include <stdlib.h>

struct employee {
  int id;
  char name[20];
  char department[20];
  int salary;
};

void main() {
  FILE *fp;
  struct employee emp;
  int choice;

  // Open the file in read and write mode
  fp = fopen("employees.dat", "r+w");

  // Do while loop to display the menu
  do {
    // Display the menu
    printf("\n1. Add employee");
    printf("\n2. Search employee");
    printf("\n3. Update employee");
    printf("\n4. Delete employee");
    printf("\n5. Exit");

    // Get the choice from the user
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Switch case to perform the selected operation
    switch (choice) {
      case 1:
        // Add employee
        printf("\nEnter employee id: ");
        scanf("%d", &emp.id);
        printf("\nEnter employee name: ");
        scanf("%s", emp.name);
        printf("\nEnter employee department: ");
        scanf("%s", emp.department);
        printf("\nEnter employee salary: ");
        scanf("%d", &emp.salary);

        // Write the employee data to the file
        fwrite(&emp, sizeof(emp), 1, fp);
        break;

      case 2:
        // Search employee
        printf("\nEnter employee id: ");
        scanf("%d", &emp.id);

        // Search for the employee in the file
        fseek(fp, (emp.id - 1) * sizeof(emp), SEEK_SET);
        fread(&emp, sizeof(emp), 1, fp);

        // If employee found, display the employee data
        if (emp.id != 0) {
          printf("\nEmployee found");
          printf("\nEmployee id: %d", emp.id);
          printf("\nEmployee name: %s", emp.name);
          printf("\nEmployee department: %s", emp.department);
          printf("\nEmployee salary: %d", emp.salary);
        } else {
          printf("\nEmployee not found");
        }
        break;

      case 3:
        // Update employee
        printf("\nEnter employee id: ");
        scanf("%d", &emp.id);

        // Search for the employee in the file
        fseek(fp, (emp.id - 1) * sizeof(emp), SEEK_SET);
        fread(&emp, sizeof(emp), 1, fp);

        // If employee found, update the employee data
        if (emp.id != 0) {
          printf("\nEnter new employee name: ");
          scanf("%s", emp.name);
          printf("\nEnter new employee department: ");
          scanf("%s", emp.department);
          printf("\nEnter new employee salary: ");
          scanf("%d", &emp.salary);

          // Write the updated employee data to the file
          fwrite(&emp, sizeof(emp), 1, fp);
          printf("\nEmployee updated");
        } else {
          printf("\nEmployee not found");
        }
        break;

      case 4:
        // Delete employee
        printf("\nEnter employee id: ");
        scanf("%d", &emp.id);

        // Search for the employee in the file
        fseek(fp, (emp.id - 1) * sizeof(emp), SEEK_SET);
        fread(&emp, sizeof(emp), 1, fp);

        // If employee found, delete the employee data
        if (emp.id != 0) {
          // Set the employee id to 0
          emp.id = 0;

          // Write the updated employee data to the file
          fwrite(&emp, sizeof(emp), 1, fp);
          printf("\nEmployee deleted");
        } else {
          printf("\nEmployee not found");
        }
        break;

      case 5:
        // Exit
        break;

      default:
        printf("\nInvalid choice");
    }
  } while (choice != 5);

  // Close the file
  fclose(fp);
}
