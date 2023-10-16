#include <stdio.h>
#define N 3
int main() {
  char *items[N] = {"Arta", "Ioannina", "Preveza"};
  const char *prefix = "";
  for (int i = 0; i < N; i++) {
    printf("%s%s", prefix, items[i]);
    prefix = ", ";
  }
  return 0;
}