#include <stdio.h>

#define SIZE 10

void get_stats(double *x, int n, double *stats) {
  stats[0] = stats[1] = stats[2] = x[0];
  for (int i = 1; i < n; i++) {
    if (x[i] < stats[0]) {
      stats[0] = x[i];
    }
    if (x[i] > stats[1]) {
      stats[1] = x[i];
    }
    stats[2] += x[i];
  }
  stats[2] /= n;
}

int main(void) {
  double table[SIZE] = {1, 2, 4, 5, 10, 11, 12, 19, 20, 21};
  double st[3];
  get_stats(table, SIZE, st);
  printf("min: %.2lf max: %.2lf mean: %.2lf\n", st[0], st[1], st[2]);
  return 0;
}
