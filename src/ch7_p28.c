#include <stdio.h>

int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr;
  // Μέγεθος πίνακα και δείκτη
  printf("Size of array (arr) = %zu bytes\n", sizeof(arr));
  printf("Size of pointer (ptr) = %zu bytes\n", sizeof(ptr));
  // Πρόσβαση στα στοιχεία μέσω δεικτοδότησης πίνακα και δείκτη
  printf("\nUsing array indexing:\n");
  for (int i = 0; i < 5; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  printf("\nUsing pointer:\n");
  for (int i = 0; i < 5; i++) {
    printf("*(ptr + %d) = %d\n", i, *(ptr + i));
  }
  // Αλλαγή διεύθυνσης δείκτη, αλλά όχι του πίνακα
  ptr++;
  // arr++; // Δεν γίνεται δεκτό από τον μεταγλωττιστή
  printf("\nAfter incrementing pointer:\n");
  printf("First element pointed by ptr = %d\n", *ptr);
  printf("First element of array = %d\n", arr[0]);
  return 0;
}
