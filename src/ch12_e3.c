#include <stdlib.h>

#define MALLOC(p, t, n) (t *)malloc(sizeof(t) * n);

int main(void) {
  int *a = MALLOC(a, int, 10);
  for (int i = 0; i < 10; i++)
    a[i] = 1;
  free(a);
}