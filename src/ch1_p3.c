#include <stdio.h>

int main(void) {
#ifdef __clang__
  printf("Compiler: Clang\n");
  printf("Version: %s\n", __clang_version__);
#elif __GNUC__
  printf("Compiler: GCC\n");
  printf("Version: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif _MSC_VER
  printf("Compiler: MSVC\n");
  printf("Version: %d\n", _MSC_VER);
#else
  printf("Unknown compiler\n");
#endif
  printf("C Standard: %ld\n", __STDC_VERSION__);
  return 0;
}
