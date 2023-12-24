#include <stdio.h>

// δήλωση συνάρτησης
int add_numbers(int a, int b);

int main(void) {
  int num1 = 5, num2 = 7;

  // κλήση συνάρτησης
  int result = add_numbers(num1, num2);
  printf("The sum is: %d\n", result);
  return 0;
}

// ορισμός συνάρτησης
int add_numbers(int a, int b) {
  int sum = a + b;
  return sum;
}
