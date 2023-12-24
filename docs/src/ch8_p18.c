#include <stdio.h>
#include <string.h>

int main(void) {
  char str[80] = "C is quirky, flawed, and an enormous success";
  const char s[2] = ","; // Ο χαρακτήρας διαχωρισμού είναι το κόμμα
  char *token;
  token = strtok(str, s);
  while (token != NULL) {
    printf(" %s\n", token);
    token = strtok(NULL, s);
  }
  return 0;
}
