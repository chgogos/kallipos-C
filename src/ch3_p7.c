#include <stdio.h>

int main(void) {
  int i, j;
  for (i = 10, j = 30; i < j; i += 7, j += 2) {
    printf("i = %d, j = %d\n", i, j);
  }
  return 0;
}
