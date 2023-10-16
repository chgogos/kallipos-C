#include <stdio.h>

typedef char string[100];

int main(void) {
  string myname;
  printf("Input your name: ");
  scanf("%s", myname);
  printf("Your name is %s\n", myname);
  return 0;
}
