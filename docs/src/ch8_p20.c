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
  char info[100];
  printf("Input test: ");
  fgets(info, 100, stdin);
  reverse(info);
  printf("Reversed text: %s\n", info);
  return 0;
}
