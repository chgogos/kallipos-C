#include <stdio.h>

#define SIZE 10

void get_stats(double *x, int n, double *stats) {
  double *min = &stats[0], *max = &stats[1], *avg = &stats[2];
  *min = x[0];
  *max = x[0];
  *avg = x[0];
  for (int i = 1; i < n; i++) {
    if (x[i] < *min) {
      *min = x[i];
    }
    if (x[i] > *max) {
      *max = x[i];
    }
    *avg += x[i];
  }
  *avg /= n;
}

int main(void) {
  double table[SIZE] = {1, 2, 4, 5, 10, 11, 12, 19, 20, 21};
  double st[3];
  get_stats(table, SIZE, st);
  printf("min: %.2lf max: %.2lf mean: %.2lf\n", st[0], st[1], st[2]);
  return 0;
}
