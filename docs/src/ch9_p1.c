#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *x = NULL;
  printf("Pointer address: %p\n", (void *)x);
  x = malloc(sizeof(int));
  *x = 100;
  printf("Pointer address: %p value: %d\n", (void*)x, *x);
  free(x);
  return 0;
}
