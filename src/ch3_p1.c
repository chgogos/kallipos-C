#include <stdio.h>

int main(void) {
  int x;
  printf("Input an integer number: ");
  scanf("%d", &x);
  if (x % 2 == 0) {
    printf("The number %d is even.\n", x);
  } else {
    printf("The number %d is odd.\n", x);
  }
  return 0;
}
