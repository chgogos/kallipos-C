// https://programming-idioms.org/idiom/167/trim-prefix
#include <stdio.h>
#include <string.h>

int main() {

  const char *p = "XXX";
  const char *s = "XXXText";
  size_t l = strlen(p);
  const char *t = strncmp(s, p, l) ? s : s + l;
  printf("%s\n", t);
}