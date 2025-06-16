#include <stdio.h>

int is_prime(int n) {
  if (n < 2)
    return 0;

  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main(void) {
  int c = 0;
  for (int i = 1000; i <= 2000; i++) {
    if (is_prime(i)) {
      c++;
    }
  }
  printf("The number of primes in [1000,2000] are %d\n", c);
  return 0;
}
