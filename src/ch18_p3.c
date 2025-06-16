#include <stdio.h>
#define N 3
int main(void) {
  char *items[N] = {"Dennis Ritchie", "Ken Thompson", "Brian Kernighan"};
  const char *prefix = "";
  for (int i = 0; i < N; i++) {
    printf("%s%s", prefix, items[i]);
    prefix = ", ";
  }
  return 0;
}
