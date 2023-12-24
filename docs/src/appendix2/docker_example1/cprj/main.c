#include <stdio.h>

int main(void) {
  char name[50];
  printf("Enter your name: ");
  scanf("%49s", name);
  printf("Hello %s! Here are some info for your system\n", name);
  printf("Macro __STDC__: %d\n", __STDC__);
  printf("Macro __STDC_VERSION__: %ld\n", __STDC_VERSION__);
#ifdef __GNUC__
  printf("Macro __GNUC__: %d\n", __GNUC__);
  printf("Macro __GNUC_MINOR__: %d\n", __GNUC_MINOR__);
  printf("Macro __GNUC_PATCHLEVEL__: %d\n", __GNUC_PATCHLEVEL__);
#endif
#if __clang__
  printf("Macro __clang_major__: %ld\n", __clang_major__);
  printf("Macro __clang_minor__: %ld\n", __clang_minor__);
  printf("Macro __clang_patchlevel__: %ld\n", __clang_patchlevel__);
#endif
}
