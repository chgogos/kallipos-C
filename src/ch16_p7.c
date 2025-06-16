#include <stdio.h>
#include <stdlib.h>

void foo(int n) {
  double *a = malloc(sizeof(double) * n);
  printf("Memory allocated for %lu bytes\n", sizeof(double) * n);
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
}

int main(void) {
  foo(10);
  foo(100);
}
