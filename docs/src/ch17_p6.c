#include <stdio.h>
#include <stdlib.h>

void cleanup(void) { printf("Program terminated blissfully!\n"); }

int main(void) {
  printf("Program Started\n");
  atexit(cleanup);
  printf("Ready to exit (y/n)? ");
  char choice;
  scanf("%c", &choice);
  if (choice == 'y' || choice == 'Y') {
    exit(1);
  } else if (choice == 'n' || choice == 'N') {
    abort();
  }
  return 0;
}
