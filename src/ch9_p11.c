#include <inttypes.h> // για τη PRIuPTR (για μορφοποίηση μεταβλητών uintptr_t)
#include <stdint.h>   // για το uintptr_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[100], lastname[100];
  int age;
} person;

void print_details(person x) {
  printf("%s %s %d \n", x.name, x.lastname, x.age);
  printf("(HEX) Address of the struct:%p [.name:%p .lastname:%p .age:%p]\n",
         (void *)&x, (void *)&x.name, (void *)&x.lastname, (void *)&x.age);
  printf("(DEC) Address of the struct:%" PRIuPTR " [.name:%" PRIuPTR
         " .lastname:%" PRIuPTR " .age:%" PRIuPTR "]\n",
         (uintptr_t)&x, (uintptr_t)&x.name, (uintptr_t)&x.lastname,
         (uintptr_t)&x.age);
}

int main(void) {
  person *mperson;
  mperson = malloc(sizeof(person));
  strcpy(mperson->name, "John");
  strcpy(mperson->lastname, "Doe");
  mperson->age = 20;
  print_details(*mperson);
  free(mperson);
  return 0;
}
