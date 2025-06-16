#include <stdio.h>

int main(void) {
  int x = 42;
  printf("The size of data type int is %zu bytes\n", sizeof(int));
  printf("The size of variable x is %zu bytes\n", sizeof x);
  printf("The size of the value of the expression x + 1.5 is %zu bytes\n",
         sizeof(x + 1.5));
  return 0;
}
