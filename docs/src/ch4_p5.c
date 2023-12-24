#include <stdio.h>

void fun(void) {
  static int a = 100;
  printf("fun: a=%d\n", a);
  a++;
}

int main(void) {
  fun();
  fun();
  fun();
  for (int i = 0; i < 3; i++) {
    static int a; // αρχικοποιείται στο μηδέν
    printf("main: a=%d\n", a);
    a++;
  }
  return 0;
}
