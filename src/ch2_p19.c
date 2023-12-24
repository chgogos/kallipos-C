#include <stdio.h>

int main(void) {
  int num1 = 10, num2 = 7;
  int max = (num1 > num2) ? num1 : num2;
  printf("num1=%d, num2=%d, max=%d\n", num1, num2, max);
  return 0;
}
