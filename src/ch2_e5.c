#include <stdio.h>

int main(void) {
  printf("0.1 + 0.2 = %f\n", 0.1 + 0.2);
  printf("0.1 + 0.3 = %f\n", 0.1 + 0.3);
  printf("0.1 + 0.2 == 0.3 is %d\n", 0.1 + 0.2 == 0.3); // false
  printf("0.1 + 0.3 == 0.4 is %d\n", 0.1 + 0.3 == 0.4); // true
  return 0;
}