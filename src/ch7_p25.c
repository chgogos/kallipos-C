#include <stdio.h>

int mylen(char *s) {
  int count = 0;
  // το '\0' είναι false
  while (*s++) {
    count++;
  }
  return count;
}

int main(void) {
  char s1[80] = "leet 1337";
  printf("Length: %d\n", mylen(s1));
  return 0;
}
