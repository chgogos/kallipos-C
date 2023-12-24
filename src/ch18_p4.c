#include <stdio.h>

int main(void) {
  int items[] = {5, 16, 7, 21, 32};
  int length = sizeof(items) / sizeof(items[0]);
  printf("%d\n", items[length - 1]);
  return 0;
}
