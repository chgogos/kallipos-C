#include <stdio.h>
#include <stdlib.h>
#define ISIZE 8

void print_array(int *x, int n) {
  for (int i = 0; i < n; i++)
    printf("%d:%d ", i, x[i]);
  printf("\n");
}

int main(void) {
  int *d = malloc(ISIZE * sizeof(int));
  int current_size = ISIZE;
  for (int i = 0; i < ISIZE; i++) {
    d[i] = i + 1;
  }
  print_array(d, current_size);
  do {
    current_size++;
    d = realloc(d, current_size * sizeof(int));
    d[current_size - 1] = rand() % 100;
    print_array(d, current_size);
  } while (current_size < 2 * ISIZE);
  free(d);
  return 0;
}
