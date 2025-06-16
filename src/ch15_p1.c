#include <assert.h>
#include <stdio.h>

enum {
  RED = 1, // change default value of RED (from 0 to 1)
  ORANGE,
  GREEN
};

int main(void) {
  static_assert(GREEN == 2, "I expect GREEN to be 2");
  return 0;
}
