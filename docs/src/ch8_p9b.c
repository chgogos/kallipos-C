// warning: 'gets' is deprecated: This function is provided for compatibility
// reasons only. Due to security concerns inherent in the design of gets(3), it
// is highly recommended that you use fgets(3) instead.

#include <stdio.h>

int main(void) {
  char s1[10], s2[10];
  printf("Input a string: ");
  gets(s1);
  fflush(stdin);
  printf("Input another string: ");
  gets(s2);
  printf("The first string is: %s\n", s1);
  printf("The second string is: %s\n", s2);
  return 0;
}
