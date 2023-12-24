#include <stdio.h>

void fun(int a) {
  auto int b = 7;
  printf("fun: a=%d b=%d\n", a, b);
}

int main(void) {
  auto int x = 42;
  fun(x);
  {
    auto int y; // η μεταβλητή y περιέχει "σκουπίδια"
    printf("main: x=%d y=%d\n", x, y);
  }
  return 0;
}
