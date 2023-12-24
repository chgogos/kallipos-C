#include <stdlib.h>

int main(void) {
  int *p = malloc(sizeof(int));
  *p = 42;
  (*p)++;
  if (*p == 42) {
    p = NULL;
  }
  free(p);
}
