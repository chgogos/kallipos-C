#include <stdio.h>

unsigned int factorial(unsigned int n) {
  unsigned int result = 1;
  while (n > 1) {
    result *= n;
    n--;
  }
  return result;
}

int main(void) {
  unsigned int num = 5;
  unsigned int result = factorial(num);
  printf("Factorial of %u is %u\n", num, result);
  return 0;
}
