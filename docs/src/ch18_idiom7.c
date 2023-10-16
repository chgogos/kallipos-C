#include <stdio.h>

int main() {
  int ch;

  while ((ch = getchar()) != EOF) {
    printf("%c", ch);
  }

  return 0;
}
