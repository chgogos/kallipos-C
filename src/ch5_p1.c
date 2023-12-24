#include <stdio.h>

int main(void) {
  float numbers[10] = {3.14,  1.62, 2.72, 0.58, 1.41,
                       0.87, 2.24, 1.73, 0.71, 0.33};
  float sum = 0;
  int i;
  for (i = 0; i < 10; i++) {
    sum += numbers[i];
  }
  float max = numbers[0];
  float min = numbers[0];
  for (i = 1; i < 10; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }
  printf("Sum=%.2f\n", sum);
  printf("Minimum=%.2f, maximum=%.2f\n", min, max);
  return 0;
}
