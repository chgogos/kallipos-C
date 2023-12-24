#include <stdio.h>

int main(void) {
  char ch;
  int count = 0;
  printf("Input a line of text: ");
  while ((ch = getchar()) != '\n') {
    count++;
  }
  printf("Total characters in line: %d \n", count);
  return 0;
}
