#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[100];
  char lastname[100];
  int age;
} person;

int main(void) {
  FILE *fp = fopen("persons.bin", "r");
  if (fp == NULL) {
    printf("Read failed!\n");
    return EXIT_FAILURE;
  }
  person a_person;
  fseek(fp, -sizeof(person), SEEK_END);
  fread(&a_person, sizeof(person), 1, fp);
  printf("Person details: %s %s %d \n", a_person.name, a_person.lastname,
         a_person.age);
  fclose(fp);
  return 0;
}
