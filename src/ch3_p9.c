#include <stdio.h>

int main(void) {
  int n = 1;
  int sum = 0;
  while (sum <= 1000) {
    sum += n;
    n++;
  }
  printf("The smallest number n such that 1+2+...+n > 1000 is: %d\n", n - 1);
  return 0;
}
