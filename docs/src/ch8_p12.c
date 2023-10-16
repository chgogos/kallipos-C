#include <stdio.h>
#include <string.h>

int main(void) {
  char x[20], y[10];
  printf("Input text: ");
  fgets(x, 10, stdin);
  fflush(stdin);
  if (strlen(x) < 10) {
    x[strlen(x) - 1] = '\0';
  }
  printf("Input another text: ");
  fgets(y, 10, stdin);
  strcat(x, y);
  printf("The concatenated text is: %s\n", x);
  return 0;
}
