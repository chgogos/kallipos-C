#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double *d = calloc(5, sizeof(double));
  printf("Initialized by calloc: ");
  for (int i = 0; i < 5; i++) {
    printf("%lf", d[i]);
    d[i] = rand() * 1.0 / RAND_MAX;
  }
  printf("\nNew: ");
  for (int i = 0; i < 5; i++) {
    printf("%lf", d[i]);
  }
  free(d);
  return 0;
}
