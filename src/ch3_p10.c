#include <stdio.h>

int main(void) {
  int choice;
  do {
    printf("Select an option:\n");
    printf("1. Print 'Hello'\n");
    printf("2. Print 'Goodbye'\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Hello\n");
      break;
    case 2:
      printf("Goodbye\n");
      break;
    case 3:
      printf("Quitting the program...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 3);
  return 0;
}
