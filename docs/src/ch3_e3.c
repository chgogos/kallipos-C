#include <stdio.h>

int main(void) {
  int accuracy;
  double pi = 1.0;
  int i = 1;
  printf("Enter the desired accuracy: ");
  scanf("%d", &accuracy);
  while (1) {
    double numerator = (double)(2 * i) * (2 * i);
    double denominator = (double)((2 * i) - 1) * ((2 * i) + 1);
    double term = numerator / denominator;
    if (term < accuracy)
      break;

    pi *= term;
    i++;
  }
  pi *= 2;
  printf("Approximation of Pi: %f\n", pi);
  return 0;
}
