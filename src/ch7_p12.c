#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main(void) {
  int (*fpointer)(int, int);
  int v1, v2;
  int a = 200, b = 100;
  fpointer = add;
  v1 = fpointer(a, b);
  fpointer = sub;
  v2 = fpointer(a, b);
  printf("Calling indirectly add() gives %d\n", v1);
  printf("Calling indirectly sub() gives %d\n", v2);
  return 0;
}
