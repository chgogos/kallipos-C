#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *fn = "test.txt";
  FILE *fp = fopen(fn, "r");
  char line[256];
  int linecount = 0;
  int charcount = 0;
  if (fp == NULL) {
    printf("An error occured on an attempt to open %s\n", fn);
    return EXIT_FAILURE;
  }
  while (fgets(line, 256, fp)) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0'; // αφαίρεση του χαρακτήρα αλλαγής
                                     // γραμμής απο το line
      charcount++; // προσμέτρηση χαρακτήρα αλλαγής γραμμής στο πλήθος
                   // χαρακτήρων
    }
    printf("%s\n", line);
    linecount++;
    charcount += strlen(line);
  }
  printf("Characters: %d\n", charcount);
  printf("Lines: %d\n", linecount);
  fclose(fp);
  return 0;
}
