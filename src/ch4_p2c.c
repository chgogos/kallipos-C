#include <stdio.h>

// πρωτότυπο fun1
int fun1(int a);

// ορισμός fun2
void fun2(int a, double b) {
  double temp = a * b;
  printf("fun2: a=%d, b=%.2lf, temp=%.2lf\n", a, b, temp);
}

int main(void) {
  int x = 5;
  double y = 2.73;

  // κλήση fun1
  int z = fun1(x);
  fun2(x, y);
  printf("main: x=%d, y=%.2lf, z=%d\n", x, y, z);
  return 0;
}

// ορισμός fun1
// int fun1(int a) {
//   printf("fun1: a=%d\n", a);
//   return a + 1;
// }