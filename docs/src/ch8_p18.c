#include <stdio.h>
#include <string.h>

int main(void) {
  char str[80] = "Information-separated-by-dashes";
  const char s[2] = "-";
  char *token;
  token = strtok(str, s);
  while (token != NULL) {
    printf(" %s\n", token);
    token = strtok(NULL, s);
  }
  return 0;
}
