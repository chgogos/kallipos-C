#include <stdio.h>

int main(void) {
  int var = 100;
  int *pt1 = &var;
  int **pt2 = &pt1;
  printf("1: var=%d pt1=%p pt2=%p\n", var, pt1, pt2);
  (*pt1)++;
  printf("2: var=%d pt1=%p pt2=%p\n", var, pt1, pt2);
  (**pt2)++;
  printf("3: var=%d pt1=%p pt2=%p\n", var, pt1, pt2);
  return 0;
}
