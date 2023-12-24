#include <stdio.h>

int main(void) {
  int num1, num2;
  int sum1 = 0, sum2 = 0;

  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);

  for (int i = 1; i <= num1 / 2; i++) {
    if (num1 % i == 0) {
      sum1 += i;
    }
  }

  for (int i = 1; i <= num2 / 2; i++) {
    if (num2 % i == 0) {
      sum2 += i;
    }
  }

  if (sum1 == num2 && sum2 == num1) {
    printf("%d and %d are friends!\n", num1, num2);
  } else {
    printf("%d and %d are not friends.\n", num1, num2);
  }

  return 0;
}
