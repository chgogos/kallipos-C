#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *p = malloc(1);
  *p = 'a';
  free(p);
  char c = *p;
  printf("%c\n", c);
}
