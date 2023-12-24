#include <errno.h>
#include <stdio.h>

int main(void) {
  FILE *fp = fopen("non_existent_file.txt", "r");
  if (fp == NULL) {
    printf("errno=%d\n", errno);
    perror("Error opening file");
  } else {
    fclose(fp);
  }
  return 0;
}
