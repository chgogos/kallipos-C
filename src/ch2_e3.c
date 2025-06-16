#include <stdio.h>
#include <string.h>

int main(void) {
  const char s[] = "Learn C";
  for (size_t i = 1; i <= strlen(s); i++) {
    printf("|%*s|\n", (int)(i + strlen(s)), s);
  }
  for (size_t i = 1; i <= strlen(s); i++) {
    printf("|%.*s|\n", (int)i, "Learn C");
  }
}
