#include <assert.h>

int main(void) {
  static_assert(sizeof(int) == 4, "int should be 4 bytes");
  return 0;
}
