#include <stdio.h>

int main(void) {
  int sum = 0;
  int a[] = {1, 1, 1, 1};
  int dummy[4] = {999, 999, 999, 999};
  for (int i = 0; i <= 4; i++) {
    sum += a[i];
  }
  printf("%d \n", sum);
  return 0;
}
