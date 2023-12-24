#include <stdio.h>

unsigned int factorial(unsigned int n) {
  // Βασική περίπτωση: το παραγοντικό του 0 και του 1 είναι 1
  if (n == 0 || n == 1) {
    return 1;
  }
  // Αναδρομική περίπτωση: n! = n * (n-1)!
  return n * factorial(n - 1);
}

int main(void) {
  unsigned int num = 5;
  unsigned int result = factorial(num);
  printf("Factorial of %u is %u\n", num, result);
  return 0;
}
