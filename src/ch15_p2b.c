#include <assert.h>

int main(void) {
  static_assert(sizeof(int) == 2, "int should be 2 bytes");
  return 0;
}
