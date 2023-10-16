#include <stdio.h>
#include <string.h>

void shift_right(char x[]) {
  char last = x[strlen(x) - 1];
  int i;
  for (i = strlen(x) - 1; i > 0; i--) {
    x[i] = x[i - 1];
  }
  x[0] = last;
}

int main(void) {
  char info[100];
  printf("Input text: ");
  fgets(info, 100, stdin);
  // αφαίρεση του χαρακτήρα νέας γραμμής από την είσοδο του χρήστη
  info[strcspn(info, "\n")] = '\0'; 
  shift_right(info);
  printf("Output text: %s\n", info);
  return 0;
}
