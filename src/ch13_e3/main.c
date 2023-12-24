#include "feature.h"
#include "utils.h"
#include <stdio.h>

int main(void) {
#ifdef DEBUG
  printf("Debugging is enabled.\n");
#endif

  feature();
  util_function();
  return 0;
}
