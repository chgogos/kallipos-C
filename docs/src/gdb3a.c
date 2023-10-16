#include <stdio.h>

int main() {
  int sum = 0;
  int a[] = {1, 1, 1, 1, 1};
  int b[] = {100, 100};
  printf("&sum=%p\n", &sum);
  printf("&x=%p\n", &b);
  for (int i = 0; i <= 5; i++) {
    printf("&a[%d]=%p ", i, &a[i]);
    sum += a[i];
  }
  printf("\n%d \n", sum);
  return 0;
}
