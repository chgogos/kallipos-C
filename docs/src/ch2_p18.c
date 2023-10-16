#include <stdio.h>

int main(void) {
  int x = 42;
  int y = 1729;
  printf("Variable x has value %d and is at address %p \n", x, (void *)&x);
  printf("Variable y has value %d and is at address %p \n", y, (void *)&y);
  int d = (&x - &y) * sizeof(int); // διαφορά σε bytes ανάμεσα σε 2 διευθύνσεις
  printf("Space in bytes between memory locations of x and y is %d\n", d);
  return 0;
}
