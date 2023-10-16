// https://programming-idioms.org/idiom/205/get-an-environment-variable
#include <stdio.h>
#include <stdlib.h>
int main() {
  const char *foo = getenv("PATH");
  if (foo == NULL)
    foo = "none";
  printf("%s\n", foo);
}