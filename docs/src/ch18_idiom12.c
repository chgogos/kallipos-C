#include <stdio.h>

int main() {
  int items[] = {21, 8, 17, 9};
  for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
    printf("%d\n", items[i]);
  }
  return 0;
}