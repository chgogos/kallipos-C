#include <stdio.h>

int main(void) {
  int x;
  printf("Input an integer number: ");
  scanf("%d", &x);
  if (x > 0)
    printf("Positive number\n");
  else if (x < 0)
    printf("Negative number\n");
  else
    printf("Zero\n");
  return 0;
}
