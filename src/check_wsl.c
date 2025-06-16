#include <stdio.h>

int main() {
#ifdef __linux__
  printf("Linux system detected\n");
#else
  printf("Non Linux system detected\n");
#endif
#ifdef __GNUC__
  printf("GCC %d.%d.%d detected\n", __GNUC__, __GNUC_MINOR__,
         __GNUC_PATCHLEVEL__);
#elif __clang__
  printf("clang %d.%d.%d detected\n", __clang_major__, __clang_minor__,
         __clang_patchlevel__);
#else
  printf("Other compiler than GCC or clang detected\n");
#endif
}