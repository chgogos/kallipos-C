#include <stdio.h>
#include <string.h>

void reverse(char x[]) {
  int N = strlen(x);
  for (int i = 0; i < N / 2; i++) {
    char t = x[i];
    x[i] = x[N - i - 1];
    x[N - i - 1] = t;
  }
}

int main(void) {
  char txt[100];
  printf("Input test: ");
  fgets(txt, 100, stdin);
  txt[strcspn(txt, "\n")] = '\0';
  reverse(txt);
  printf("Reversed text: %s\n", txt);
  return 0;
}
