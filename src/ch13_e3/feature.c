#include "feature.h"
#include <stdio.h>

void feature(void) {
#ifdef DEBUG
  printf("Feature in development mode.\n");
#else
  printf("Feature in production mode.\n");
#endif
}
