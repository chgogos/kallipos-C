#include <stdio.h>

int main(void) {
  printf("Macro __DATE__: %s\n", __DATE__);
  printf("Macro __TIME__: %s\n", __TIME__);
  printf("Macro __FILE__: %s\n", __FILE__);
  printf("Macro __LINE__: %d\n", __LINE__);
  printf("Macro __STDC__: %d\n", __STDC__);
  printf("Macro __STDC_VERSION__: %ld\n", __STDC_VERSION__);
}
