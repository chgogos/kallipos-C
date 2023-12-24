#include <math.h>
#include <stdio.h>

int main(void) {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);
  if (b == 0) {
    goto error_handling;
  }
  if (a < 0) {
    goto error_handling;
  }
  printf("a=%d, b=%d, a/b=%.2f, sqrt(a)=%.2f\n", a, b, (float)a / b, sqrt(a));
  return 0;

error_handling:
  printf("Error: because math!\n");
  return 1;
}
