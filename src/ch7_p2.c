#include <stdio.h>

int main(void) {
  int a = 100;
  double b = 200;
  int *x = NULL; // είναι καλή πρακτική να αρχικοποιούμε τους δείκτες με την τιμή NULL
  double *z = NULL;
  printf("Sizes of variables %zu and %zu \n", sizeof(a), sizeof(b));
  printf("Sizes of pointers %zu and %zu \n", sizeof(x), sizeof(z));
  return 0;
}
