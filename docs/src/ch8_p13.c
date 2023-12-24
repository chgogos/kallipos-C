#include <stdio.h>
#include <string.h>

void concat(char z[], const char x[], const char y[]) {
  int count = 0;
  for (size_t i = 0; i < strlen(x); i++) {
    z[count++] = x[i];
  }
  for (size_t i = 0; i < strlen(y); i++) {
    z[count++] = y[i];
  }
  z[count] = '\0';
}

int main(void) {
  char x[10], y[10], z[50];
  printf("Input text: ");
  fgets(x, 10, stdin);
  fflush(stdin);
  printf("Input another text: ");
  fgets(y, 10, stdin);
  concat(z, x, y);
  printf("The concatenated text is %s\n", z);
  return 0;
}
