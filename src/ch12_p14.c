#include <stdio.h>

int main(void) {
  printf("Tracing file %s at line %d\n", __FILE__, __LINE__);
#line 100
  printf("Tracing file %s at line %d\n", __FILE__, __LINE__);
#line 1 "dummy.c"
  printf("Tracing file %s at line %d\n", __FILE__, __LINE__);
}
