#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *p = malloc(1);
  *p = 'a';
  char c = *(p + 1);
  printf("%c\n", c);
  free(p);
}
