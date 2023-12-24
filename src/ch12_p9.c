#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

int main(void) {
  int x = 0;
  int y = ++x;
#if DEBUG
  fprintf(stderr, "DEBUG: x=%d, y=%d\n", x, y);
#endif
  printf("bye");
}
