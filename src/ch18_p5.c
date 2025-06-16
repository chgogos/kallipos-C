#include <stdio.h>

int main(void) {
  int items[] = {8, 17, 9, 42, 73, 21};
  for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
    printf("%d\t", items[i]);
  }
  printf("\n");
  return 0;
}
