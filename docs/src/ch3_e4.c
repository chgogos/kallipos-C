#include <stdio.h>

int main(void) {
  int terms;
  double pi = 1.0;
  printf("Enter number of terms that will be used to approximate pi: ");
  scanf("%d", &terms);
  for (int i = 1; i <= terms; i++) {
    double numerator = (2. * i) * (2. * i);
    double denominator = ((2. * i) - 1) * ((2. * i) + 1);
    double term = numerator / denominator;
    pi *= term;
  }
  pi *= 2;
  printf("Approximation of Pi: %f\n", pi);
  return 0;
}
