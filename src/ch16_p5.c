#include <stdio.h>
#include <stdlib.h>

void foo(int n) {
  double *a = malloc(sizeof(double) * n);
  printf("Memory allocated of %lu bytes\n", sizeof(double) * n);
}

int main(void) {
  foo(10);
  foo(100);
}
