#include <stdio.h>

int main(void) {
  char s1[10], s2[10];
  printf("Input a string: ");
  fgets(s1, 10, stdin);
  printf("Input another string: ");
  fgets(s2, 10, stdin);
  printf("The first string is: %s\n", s1);
  printf("The second string is: %s\n", s2);
  return 0;
}
