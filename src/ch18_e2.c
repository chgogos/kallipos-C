#include <stdio.h>

int main(void) {
  for (int x = 1; x <= 100; x++) {
    for (int y = 1; y <= 100; y++) {
      for (int z = 1; z <= 100; z++) {
        if (12 * x - 14 * y + 81 * z == 100) {
          printf("Solution: x = %d, y = %d, z = %d\n", x, y, z);
        }
      }
    }
  }
  return 0;
}
