#include <stdio.h>
#include <stdlib.h>

void fill_random(int *x, int n) {
  for (int i = 0; i < n; i++) {
    x[i] = rand() % 100;
  }
}

void print_array(int *x, int n) {
  for (int i = 0; i < n; i++) {
    printf("%4d", x[i]);
  }
  printf("\n");
}

int main(void) {
  int *dynamic[5];
  // δημιουργία ενός δισδιάστατου πίνακα 5 γραμμών
  // με 5 στοιχεία στην πρώτη γραμμή, 4 στη δεύτερη κ.ο.κ.
  for (int i = 0; i < 5; i++) {
    int elements = 5 - i;
    dynamic[i] = malloc(elements * sizeof(int));
    fill_random(dynamic[i], elements);
    print_array(dynamic[i], elements);
  }
  for (int i = 0; i < 5; i++) {
    free(dynamic[i]);
  }
  return 0;
}
