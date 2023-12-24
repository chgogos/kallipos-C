#include <stdio.h>
#define N 10000

int main(void) {
  for (int num1 = 1; num1 <= N; num1++) {
    int sum1 = 0;
    for (int i = 1; i <= num1 / 2; i++) {
      if (num1 % i == 0) {
        sum1 += i;
      }
    }
    for (int num2 = num1 + 1; num2 <= N; num2++) {
      int sum2 = 0;
      for (int i = 1; i <= num2 / 2; i++) {
        if (num2 % i == 0) {
          sum2 += i;
        }
      }
      if (sum1 == num2 && sum2 == num1) {
        printf("%d and %d are friends!\n", num1, num2);
      }
    }
  }
  return 0;
}
