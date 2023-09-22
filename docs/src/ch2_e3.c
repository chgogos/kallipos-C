#include <stdio.h>
#include <string.h>

int main() {
  char s[] = "Learn C";
  for (int i = 1; i <= strlen(s); i++) {
    printf("|%*s|\n", i + strlen(s), s);
  }
  for (int i = 1; i <= strlen(s); i++) {
    printf("|%.*s|\n", i, "Learn C");
  }
}