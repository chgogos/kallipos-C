#include <stdio.h>

void calc_min_max(int n, int *min, int *max) {
  int x;
  for (int i = 0; i < n; i++) {
    printf("Input a value: ");
    scanf("%d", &x);
    if (i == 0 || x < *min) {
      *min = x;
    }
    if (i == 0 || x > *max) {
      *max = x;
    }
  }
}

int main(void) {
  int min_value, max_value;
  calc_min_max(5, &min_value, &max_value);
  printf("min: %d max: %d\n", min_value, max_value);
  return 0;
}
