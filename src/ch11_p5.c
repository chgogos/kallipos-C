#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *fn = "test.txt";
  FILE *fp = fopen(fn, "r");
  if (fp == NULL) {
    printf("An error occured on an attempt to open %s\n", fn);
    return EXIT_FAILURE;
  }
  printf("File %s opened successfully (for read)\n", fn);
  fclose(fp);
  return 0;
}
