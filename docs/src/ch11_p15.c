#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[100];
  char lastname[100];
  int age;
} person;

int main(void) {
  FILE *fp = fopen("persons.bin", "w");
  if (fp == NULL) {
    printf("Write failed!\n");
    return EXIT_FAILURE;
  }
  person p[2] = {{"John", "Doe", 46}, {"Richard", "Roe", 33}};
  fwrite(p, sizeof(person), 2, fp);
  fclose(fp);
  return 0;
}
