#include <setjmp.h>
#include <stdio.h>

jmp_buf buf;

void bar(void) {
  int x;
  printf("1: bar\n");
  printf("Input value -99 to go back to main() and end program: ");
  scanf("%d", &x);
  if (x == -99) {
    longjmp(buf, 1);
  }
  printf("2: bar\n");
}

void foo(void) {
  printf("1: foo\n");
  bar();
  printf("2: foo\n");
}

int main(void) {
  printf("1: main\n");
  while (setjmp(buf) == 0) {
    printf("2: main\n");
    foo();
    printf("3: main\n");
  }
  printf("Returning directly to main()\n");
  return 0;
}
