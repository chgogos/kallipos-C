#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  int count = 0;
  char filename[100];
  printf("Input the name of the file: ");
  fgets(filename, 100, stdin);
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Write to file %s failed!\n", filename);
    return EXIT_FAILURE;
  }
  printf("Input a number of characters: ");
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    char c = (char)('A' + rand() % 26);
    printf("%c", c);
    fputc(c, fp);
  }
  fclose(fp);
  return 0;
}
