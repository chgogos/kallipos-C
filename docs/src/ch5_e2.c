#include <stdio.h>

int inner_product(const int arr1[], const int arr2[], int size) {
  int result = 0;
  for (int i = 0; i < size; i++) {
    result += arr1[i] * arr2[i];
  }
  return result;
}

int main(void) {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {2, 4, 6, 8, 10};
  int size = sizeof(arr1) / sizeof(arr1[0]);
  int dot_product = inner_product(arr1, arr2, size);
  printf("Inner Product (Dot Product): %d\n", dot_product);
  return 0;
}
