#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(char *source, char *dest, int pos, int n) {
  int icount = 0;
  for (int i = pos; i < pos + n; i++) {
    dest[icount++] = source[i];
  }
  dest[icount] = '\0';
}

int main(void) {
  char p[100], subp[100];
  int start, letters;
  printf("Input a string: ");
  fgets(p, 100, stdin);
  printf("Input start posistion: ");
  scanf("%d", &start);
  printf("Input number of characters: ");
  scanf("%d", &letters);
  substring(p, subp, start, letters);
  printf("The substring is: %s \n", subp);
  return 0;
}
