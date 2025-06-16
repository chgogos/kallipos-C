#include <stdio.h>

int main(void) {
  int x, h, m, s;
  printf("Enter duration in seconds:");
  scanf("%d", &x);
  h = x / 3600;
  x %= 3600;
  m = x / 60;
  s = x % 60;
  printf("%02d:%02d:%02d\n", h, m, s);
  return 0;
}
