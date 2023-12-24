#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(void) {
  int num_elements = 5;
  int *arr = (int *)calloc(num_elements, sizeof(int));
  if (arr == NULL) {
    printf("Initial memory allocation failed!\n");
    exit(1);
  }
  printf("Initial memory allocation successful!\n");
  print_array(arr, num_elements);
  num_elements = 10;
  // Αλλαγή μεγέθους πίνακα για να χωρά 10 τιμές
  int *resized_arr = (int *)realloc(arr, num_elements * sizeof(int));
  if (resized_arr == NULL) {
    printf("Memory reallocation failed!\n");
    exit(1);
  }
  printf("Memory reallocation successful!\n");
  arr = resized_arr; // Ενημέρωση του δείκτη προς το νέο πίνακα
  print_array(arr, num_elements);
  free(arr); // απελευθέρωση μνήμης, είτε πέτυχε η αλλαγή μεγέθους είτε όχι
  return 0;
}
