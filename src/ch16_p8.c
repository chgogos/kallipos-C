#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *a = malloc(sizeof(int) * 10);
  if (a[5] > 0) {
    printf("A\n");
  } else {
    printf("B\n");
  }
  free(a);
}
