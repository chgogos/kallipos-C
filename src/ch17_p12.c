#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *s1, *s2, s3[80];
  {
    const char *t = "First, solve the problem. Then, write the code.";
    s1 = strdup(t);
    s2 = strndup(t, 25); // διπλότυπο των 25 πρώτων χαρακτήρων του t
    strcpy(s3, t);
  }
  printf("string at %p: %s\n", (void *)s1, s1);
  printf("string at %p: %s\n", (void *)s2, s2);
  printf("string at %p: %s\n", (void *)s3, s3);
  free(s1);
  free(s2);
  return 0;
}
