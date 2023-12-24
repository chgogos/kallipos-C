#include <stdio.h>

void bar(int);     // εμπρόσθια δήλωση (forward declaration)
int baz(int, int); // εμπρόσθια δήλωση

void foo(void) {
  printf("foo(%p) pushed in the call stack\n", __builtin_frame_address(0));
  int a = 1;
  bar(a);
  printf("foo: a(%p)=%d\n", (void *)&a, a);
  printf("foo popped from the call stack\n");
}

void bar(int b) {
  printf("bar(%p) pushed in the call stack\n", __builtin_frame_address(0));
  int c = 2;
  int d = baz(b, c);
  printf("bar: b(%p)=%d c(%p)=%d, d(%p)=%d\n", (void *)&b, b, (void *)&c, c,
         (void *)&d, d);
  printf("bar popped from the call stack\n");
}

int baz(int e, int f) {
  printf("baz(%p) pushed in the call stack\n", __builtin_frame_address(0));
  printf("baz: e(%p)=%d f(%p)=%d\n", (void *)&e, e, (void *)&f, f);
  printf("baz popped from the call stack\n");
  return e + f;
}

int main(void) {
  printf("main(%p) pushed in the call stack\n", __builtin_frame_address(0));
  foo();
  printf("main popped from the call stack\n");
  return 0;
}
