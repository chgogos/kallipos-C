#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[80];
  char s2[] = "Hello from phrase2";
  char *s3 = "Hello from phrase3";
  strcpy(s1, "Static String");
  printf("s1=%s s2=%s s4=%s \n", s1, s2, s3);
  return 0;
}
