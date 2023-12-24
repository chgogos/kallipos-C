#include <stdio.h>
#include <string.h>

int main(void) {
  char x[10], y[10];
  do {
    printf("Input a text: ");
    fgets(x, 10, stdin);
    printf("Input another text: ");
    fgets(y, 10, stdin);
  } while (strcmp(x, y) != 0);
  return 0;
}
