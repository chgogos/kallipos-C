#include <stdio.h>

int sum_of_digits(int n) {
  if (n < 10) {
    return n;
  } else {
    return n % 10 + sum_of_digits(n / 10);
  }
}

int main(void) {
  int number;
  printf("Enter a positive integer: ");
  scanf("%d", &number);
  int result = sum_of_digits(number);
  printf("Sum of digits: %d\n", result);
  return 0;
}
