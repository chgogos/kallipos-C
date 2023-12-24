#include <stdlib.h>

int *get_values(void) {
  static int values[5] = {4, 7, 2, 3, 9};
  return values;
}
