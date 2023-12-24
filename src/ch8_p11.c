#include <stdio.h>
#include <string.h>

int main(void) {
  char x[100];
  printf("Input a line of text: ");
  fgets(x, 100, stdin);
  printf("You have entered: %s\n", x);
  printf("The length of the text that you entered is: %zu\n", strlen(x));
  return 0;
}
