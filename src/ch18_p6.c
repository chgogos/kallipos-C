#include <stdio.h>

int main(void) {
  int ch;
  while ((ch = getchar()) != EOF) {
    printf("%c", ch);
  }
  printf("Input ended\n"); // Ctrl+D για EOF στο Linux - MacOS
                           // Ctrl+Z για EOF στα Windows
  return 0;
}
