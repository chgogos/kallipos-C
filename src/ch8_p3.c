#include <stdio.h>

int main(void) {
  char letter, next_letter;
  int code, next_code;
  letter = 'A';
  code = letter;
  next_letter = letter + 1;
  next_code = next_letter;
  printf("The first character is %c\n", letter);
  printf("The ASCII code of the first character is %d\n", code);
  printf("The next character is %c\n", next_letter);
  printf("The ASCII code of the first character is %d\n", next_code);
  return 0;
}
