#include <stdio.h>

int main(void) {
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j > 0; j--) {
      printf("%d ", j);
    }
    printf("\n");
  }
  return 0;
}
