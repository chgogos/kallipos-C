#include <stdio.h>

void DoSomethingWith(int *x) { printf("%d\n", *x); }

int main() {
  int items[] = {1, 2, 3};
  for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
    DoSomethingWith(&items[i]);
  }
}