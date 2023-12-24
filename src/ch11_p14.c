#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[100];
  char lastname[100];
  int age;
} person;

int main(void) {
  person p = {"John", "Doe", 46};
  person x = {"Richard", "Roe", 33};
  FILE *fp = fopen("persons.bin", "w");
  if (fp == NULL) {
    printf("Write failed!\n");
    return EXIT_FAILURE;
  }
  fwrite(&p, sizeof(person), 1, fp);
  fwrite(&x, sizeof(person), 1, fp);
  fclose(fp);
  return 0;
}
