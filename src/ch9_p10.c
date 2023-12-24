#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ISIZE 8

void print_array(int *x, int n) {
  printf("Array of size %d: ", n);
  for (int i = 0; i < n; i++) {
    printf("%d:%d ", i, x[i]);
  }
  printf("\n");
}

int main(void) {
  srand(time(NULL)); // αρχικοποίηση της συνάρτησης rand()
  int *d = malloc(ISIZE * sizeof(int));
  int current_size = ISIZE;
  for (int i = 0; i < ISIZE; i++) {
    d[i] = rand() % 10; // τυχαίος ακέραιος από το 0 έως το 9
  }
  print_array(d, current_size);
  do {
    current_size++;
    d = realloc(d, current_size * sizeof(int));
    d[current_size - 1] = rand() % 10; // τυχαίος ακέραιος από το 0 έως το 9
    print_array(d, current_size);
  } while (current_size < 2 * ISIZE);
  free(d);
  return 0;
}
