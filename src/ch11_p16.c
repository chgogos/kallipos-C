#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[100];
  char lastname[100];
  int age;
} person; 

void print_person(person p) {
  printf("Firstname: %s, Lastname: %s, Age: %4d\n", p.name, p.lastname, p.age);
}

int main(void) {
  FILE *fp = fopen("persons.bin", "r"); 
  if (fp == NULL) {
    printf("Read failed!\n");
    return EXIT_FAILURE;
  }
  person data[2];
  fread(data, sizeof(person), 2, fp); 
  for (int i = 0; i < 2; i++) {
    print_person(data[i]);
  }
  fclose(fp);
  return 0;
}
