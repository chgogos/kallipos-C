#include <stdio.h>
#include <stdlib.h>

double avg(int *x, int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += x[i];
  }
  return sum / n;
}

int main(void) {
  int n;
  int *v;
  printf("Input the number of elements: ");
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    printf("Input value for element %d/%d: ", i + 1, n);
    scanf("%d", &v[i]);
  }
  printf("Mean value: %lf \n", avg(v, n));
  free(v);
  return 0;
}
