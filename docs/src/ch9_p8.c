#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_binary(int n) {
  int count = 0;
  while (n != 0) {
    n = n / 2;
    count++;
  }
  return count;
}

void convert(int n, char *b) {
  int pos = 0;
  while (n != 0) {
    int d = n % 2;
    n = n / 2;
    b[pos++] = '0' + d;
  }
  b[pos] = '\0';
}
void reverse(char *b) {
  for (size_t i = 0; i < strlen(b) / 2; i++) {
    char c = b[i];
    b[i] = b[strlen(b) - i - 1];
    b[strlen(b) - i - 1] = c;
  }
}
int main(void) {
  int number;
  char *binary;
  printf("Input a positive number: ");
  scanf("%d", &number);
  int digits = count_binary(number);
  binary = malloc((digits + 1) * sizeof(char));
  convert(number, binary);
  reverse(binary);
  printf("Binary representation of %d: %s\n", number, binary);
  free(binary);
  return 0;
}
