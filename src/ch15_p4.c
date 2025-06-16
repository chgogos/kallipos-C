#include <stdio.h>

void fun(int a) {
  printf("File:%s Function:%s Line:%d a=%d\n", __FILE__, __func__, __LINE__, a);
}

int main(void) {
  fun(42);
  return 0;
}
