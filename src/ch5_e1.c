#include <stdio.h>

void reverse_array(int arr[], int size) {
  int start = 0;
  int end = size - 1;
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

int main(void) {
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Original Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  reverse_array(arr, size);
  printf("\nReversed Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
