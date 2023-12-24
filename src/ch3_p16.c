#include <stdio.h>

int main(void) {
  int num;
loop:
  printf("Enter a number (-1 to exit): ");
  scanf("%d", &num);
  if (num != -1) {
    printf("You entered: %d\n", num);
    goto loop;
  }
  printf("Loop terminated.\n");
  return 0;
}
