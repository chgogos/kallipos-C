#include <stdio.h>

#define MACRO_VA_ARGS(x, ...) (x), __VA_ARGS__

int main(void) {
  printf("arg0=%d, arg1=%s\n", MACRO_VA_ARGS(42, "foo"));
  printf("arg0=%d, arg1=%s, arg2=%f\n", MACRO_VA_ARGS(42, "foo", 3.141592));
}
