#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *fn = "test.txt";
  FILE *fp = fopen(fn, "r");
  char ch = ' ';
  int charcount = 0, linecount = 0;
  if (fp == NULL) {
    printf("An error occured on an attempt to open %s\n", fn);
    return EXIT_FAILURE;
  }
  do {
    ch = fgetc(fp);
    if (ch != EOF) {
      printf("%c", ch);
      charcount++;
      if (ch == '\n') {
        linecount++;
      }
    }
  } while (ch != EOF);
  // Αν η τελευταία γραμμή δεν τελειώνει με αλλαγή γραμμής
  if (ch != '\n') {
    linecount++;
  }
  // Αν το αρχείο είναι κενό
  if (charcount == 0) {
    linecount = 0;
  }
  printf("\nCharacters: %d\n", charcount);
  printf("Lines: %d\n", linecount);
  fclose(fp);
  return 0;
}
