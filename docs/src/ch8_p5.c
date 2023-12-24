#include <ctype.h>
#include <stdio.h>

int main(void) {
  char ch;
  int charcount = 0;
  int digitcount = 0;
  int lowercount = 0;
  printf("Enter a line of text: ");
  while ((ch = getchar()) != '\n') {
    charcount++;
    if (isdigit(ch)) {
      digitcount++;
    }
    if (islower(ch)) {
      lowercount++;
    }
  }
  printf("Total characters in line: %d\n", charcount);
  printf("Digits: %.2lf%%\n", digitcount * 100.0 / charcount);
  printf("Lower letters: %.2lf%%\n", lowercount * 100.0 / charcount);
  return 0;
}
