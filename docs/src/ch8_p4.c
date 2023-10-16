#include <stdio.h>

int main(void) {
  char letter;
  char uppercase;
  printf("Input a sequence of letters ending with #: ");
  do {
    scanf("%c", &letter);
    if (letter >= 'a' && letter <= 'z') {
      uppercase = letter - ('a' - 'A'); // αφαιρεί την τιμή 32
      printf("%c", uppercase);
    }
  } while (letter != '#');
  printf("\n");
  return 0;
}

