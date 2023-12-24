#include <stdio.h>

int main(void) {
  int x[] = {10, 20, 200, 300, 400}; // πίνακας 5 θέσεων
  int element = 200;                 // τιμή προς αναζήτηση
  int *px = &x[0];
  // ατέρμονας βρόχος που θα διακοπεί με break
  while (1) {
    if (*px == element) {
      printf("Value %d found at position %ld\n", element, px - &x[0]);
      break;
    }
    if (px == &x[4]) {
      printf("Value %d not found\n", element);
      break;
    }
    px++;
  }
  return 0;
}
