#include <stdio.h>

int main(void) {
  char c = 'A';
  char *p2c = &c;
  int i = 100;
  int *p2i = &i;
  printf("c=%c i=%d p2c=%p p2i=%p\n", c, i, (void*)p2c, (void*)p2i);
  p2c++;
  p2i++;
  printf("c=%c i=%d p2c=%p p2i=%p\n", c, i, (void*)p2c, (void*)p2i);
  p2i--;
  printf("c=%c i=%d p2c=%p p2i=%p\n", c, i, (void*)p2c, (void*)p2i);
  return 0;
}
