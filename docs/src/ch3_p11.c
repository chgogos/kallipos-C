#include <stdio.h>

int main(void) {
  int i, x, sum = 0;
  for (i = 0; i < 5; i++) {
    printf("Enter a value: ");
    scanf("%d", &x);
    if (x == -1)
      break;
    sum += x;
  }
  printf("The sum is %d\n", sum);
  return 0;
}
