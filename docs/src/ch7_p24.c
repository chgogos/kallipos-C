#include <stdio.h>
#include <string.h>

int find_digits(char *s) {
  int count = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      count++;
    }
  }
  return count;
}

int main(void) {
  char s1[80] = "leet 1337";
  printf("Digits: %d\n", find_digits(s1));
  return 0;
}
