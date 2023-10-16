#include <stdio.h>

struct person {
  char name[100];
  char lastname[100];
  int age;
  double height;
};

int main(void) {
  struct person a_person;
  printf("Input data for a person\n");
  printf("First name: ");
  scanf("%s", a_person.name);
  printf("Last name: ");
  scanf("%s", a_person.lastname);
  printf("Age: ");
  scanf("%d", &a_person.age);
  printf("Height: ");
  scanf("%lf", &a_person.height);
  printf("Person's data\n");
  printf("%s %s\n", a_person.name, a_person.lastname);
  printf("%d %lf\n", a_person.age, a_person.height);
  if (a_person.age >= 18)
    printf("Adult\n");
  else
    printf("Not an adult\n");
  return 0;
}
