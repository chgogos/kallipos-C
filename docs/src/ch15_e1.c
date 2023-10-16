#include <stdio.h>

// swap 2 variables (WRONG!)
void swap(int a, int b) {
  a = a + b;
  b = a - b;
  a = a - b;
}

int main() {
  int x = 5, y = 10;
  swap(x, y);
  printf("x = %d, y = %d\n", x, y);
}