#include <stdio.h>

struct person {
  char name[100];
  char lastname[100];
  int age;
  double height;
} a_person = {"Giannis", "Pappas", 37, 171};

int main(void) {
  printf("Person's data\n");
  printf("%s %s\n", a_person.name, a_person.lastname);
  printf("%d %lf\n", a_person.age, a_person.height);
  if (a_person.age >= 18)
    printf("Adult\n");
  else
    printf("Not an adult\n");
  return 0;
}
