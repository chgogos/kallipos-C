#include <stdio.h>

int global_var = 10;

void fun(void) {
  int local_var = 5;
  printf("fun: local_var=%d\n", local_var);
  printf("fun: global_var=%d\n", global_var);
  global_var++;
  local_var++;
}

int main(void) {
  int local_var = 7;
  printf("main: local_var=%d\n", local_var);
  printf("main: global_var=%d\n", global_var);
  fun();
  global_var++;
  printf("main: local_var=%d\n", local_var);
  printf("main: global_var=%d\n", global_var);
  return 0;
}
