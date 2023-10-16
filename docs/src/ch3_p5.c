#include <stdio.h>

int main(void) {
  char c;
  printf("Is C a great language? ");
  scanf("%c", &c);
  switch (c) {
  case 'y':
  case 'Y':
    printf("I agree!\n");
    break;
  case 'n':
  case 'N':
    printf("Think again!\n");
    break;
  default:
    printf("I will take that as a yes!\n");
  }
  return 0;
}
