// https://programming-idioms.org/idiom/142/hexadecimal-digits-of-an-integer/2402/c

#include <stdio.h>

int main() {
  char s[32];
  int i = 42424242;
  snprintf(s, sizeof(s), "%x", i);
  printf("%s\n", s);
  return 0;
}