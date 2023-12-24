#include <stdio.h>

int mystrlen(const char x[]) {
  int count = 0;
  while (x[count] != '\0') {
    count++;
  }
  return count;
}

int main(void) {
  char x[100];
  printf("Input a line of text: ");
  fgets(x, 100, stdin);
  printf("You have entered: %s", x);
  printf("The length of the text that you entered is: %d\n", mystrlen(x));
  return 0;
}
