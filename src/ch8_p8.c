#include <stdio.h>

int main(void) {
  char x[100];
  printf("Enter X \n");
  scanf("%99s", x);
  printf("x = %s\n", x);
  return 0;
}
