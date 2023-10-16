#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[100], lastname[100];
  int age;
} person;

void print_details(person x) {
  printf("%s %s %d \n", x.name, x.lastname, x.age);
}

int main(void) {
  person *mperson;
  mperson = malloc(sizeof(person));
  strcpy(mperson->name, "Ioannis");
  strcpy(mperson->lastname, "Pappas");
  mperson->age = 20;
  print_details(*mperson);
  free(mperson);
  return 0;
}
