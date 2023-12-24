#include <stdio.h>

int main(void) {
  char x[10];
  x[0] = 'L';
  x[1] = 'E';
  x[2] = 'E';
  x[3] = 'T';
  x[4] = '\0';
  printf("The string is %s\n", x);
  return 0;
}
