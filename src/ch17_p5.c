#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int choice;
  printf("How do you want to stop the program (1=exit, 2=abort, 3=return)? ");
  scanf("%d", &choice);
  if (choice == 1) {
    printf("Let's set the exit status to 99.\n");
    exit(99);
  } else if (choice == 2) {
    printf("Abort.\n");
    abort();
  }
  return 0;
}
