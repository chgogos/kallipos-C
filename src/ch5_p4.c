#include <stdio.h>

void insertion_sort(int arr[], int size) {
  int i, j, key;
  for (i = 1; i < size; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main(void) {
  int numbers[] = {12, 11, 13, 5, 6};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  printf("Original Array=");
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  insertion_sort(numbers, size);
  printf("\nSorted Array=");
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  return 0;
}
