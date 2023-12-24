#include <stdio.h>

int main(void) {
  char a = 'a';
  char b = '1';
  printf("a=%c, b=%c\n", a, b);
  printf("Input a value for a char variable: ");
  scanf("%c", &b);
  printf("a=%c, b=%c\n", a, b);
  return 0;
}
