#include <stdio.h>

int main(void) {
  char s[20];
  printf("Enter name: ");
  fgets(s, sizeof(s), stdin);
  printf("%s\n", s);
  return 0;
}
