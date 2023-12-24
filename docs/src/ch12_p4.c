#include <stdio.h>

#define STRINGIZE_INT(x) printf(#x " = %d\n", x)

int main(void) {
  int a = 42;

  STRINGIZE_INT(a);
  STRINGIZE_INT(a + 1);
}
