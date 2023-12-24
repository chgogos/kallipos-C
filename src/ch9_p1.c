#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *ptr = NULL;
  printf("Pointer address: %p\n", (void *)ptr);
  ptr = malloc(sizeof(int));
  *ptr = 100;
  printf("Pointer address: %p value: %d\n", (void*)ptr, *ptr);
  free(ptr);
  return 0;
}
