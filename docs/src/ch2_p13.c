#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int x = 0;
  bool f = (x == 0 || (10 / x) > 1);
  printf("The logic expression's value is %d\n", f);
  return 0;
}
