#include <stdarg.h>
#include <stdio.h>

double average(int n, ...) {
  va_list args;
  va_start(args, n);
  double x, sum = 0;
  for (int i = 0; i < n; i++) {
    x = va_arg(args, double);
    sum += x;
  }
  va_end(args);
  return sum / n;
}

int main(void) {
  printf("Average: %.2f\n", average(3, 1.5, 2.7, 3.9));
  printf("Average: %.2f\n", average(4, 1.5, 2.7, 3.9, 4.5));
  printf("Average: %.2f\n", average(5, 1.5, 2.7, 3.9, 4.5, 6.3));
  return 0;
}
