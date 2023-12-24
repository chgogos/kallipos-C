#include <stdio.h>

void recursive_function(void) {
  static int c = 0;
  printf("Call %d, frame address = %p\n", ++c, __builtin_frame_address(0));
  recursive_function();
}

int main(void) {
  recursive_function();
  return 0;
}
