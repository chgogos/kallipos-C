#include <stdio.h>

int calc_min(int n) {
  int min = 0, x;
  for (int i = 0; i < n; i++) {
    printf("Input a value: ");
    scanf("%d", &x);
    if (i == 0 || x < min) {
      min = x;
    }
  }
  return min;
}

int main(void) {
  int min_value = calc_min(5);
  printf("Min = %d\n", min_value);
  return 0;
}
