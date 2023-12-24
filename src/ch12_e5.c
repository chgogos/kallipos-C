#include <stdio.h>

#define IS_GCC (defined(__GNUC__) && !defined(__clang__))

int main(void) {
#if IS_GCC
  printf("GCC detected");
#else
  printf("GCC is not detected");
#endif
}