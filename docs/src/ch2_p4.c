#include <stdio.h>

int main(void) {
  int dividend = 42, divisor1 = 2, divisor2 = 0;
  fprintf(stdout, "Info: %d/%d = %d\n", dividend, divisor1,
          dividend / divisor1);
  fprintf(stderr, "Error: division by zero if %d/%d is to be attempted\n",
          dividend, divisor2);
  return 0;
}
