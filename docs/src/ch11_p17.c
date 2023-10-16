#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *fn = "persons.bin";
  FILE *fp;
  int len;
  fp = fopen(fn, "r");
  if (fp == NULL) {
    printf("Read failed!\n");
    return EXIT_FAILURE;
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp);
  fclose(fp);
  printf("Size of %s = %d bytes\n", fn, len);
  return 0;
}
