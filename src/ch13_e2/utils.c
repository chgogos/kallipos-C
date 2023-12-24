#include "utils.h"
#include <stdio.h>

void print_message(const char *message) { printf("%s\n", message); }

void print_result(const char *operation, int result) {
  printf("%s result: %d\n", operation, result);
}
