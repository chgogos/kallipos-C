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

void dec2hex(int n, char x[]) {
  int i = 0;
  const char charsafter10[] = "ABCDEF";
  while (n != 0) {
    int b = n % 16;
    n = n / 16;
    if (b < 10) {
      x[i++] = b + '0';
    } else {
      x[i++] = charsafter10[b - 10];
    }
  }
  x[i] = '\0';
  reverse(x);
}

int main(void) {
  char s[100];
  int funny[] = {64206, 48879, 12648430, 64222, 61453};
  for (int i = 0; i < 5; i++) {
    dec2hex(funny[i], s);
    printf("Decimal: %d Hexadecimal: %s\n", funny[i], s);
  }
  return 0;
}
