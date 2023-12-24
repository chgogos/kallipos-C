#include <stdio.h>

void fun(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      a[i] = 0;
    }
  }
}

int main(void) {
  int a[] = {1, -2, 3, -4, 5, -6, 7, -8, 9};
  for (int i = 0; i < 9; i++) {
    printf("%2d ", a[i]);
  }
  printf("\n");
  fun(a, 9);
  for (int i = 0; i < 9; i++) {
    printf("%2d ", a[i]);
  }
  printf("\n");
  return 0;
}
