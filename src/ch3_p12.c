#include <stdio.h>

int main(void) {
  for (;;) {
    int x;
    printf("Enter a number (-1 to exit): ");
    scanf("%d", &x);
    if (x == -1)
      break;
    printf("You entered: %d\n", x);
  }
  printf("Loop terminated.\n\n");
  return 0;
}
