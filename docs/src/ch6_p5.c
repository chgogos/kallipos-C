#include <stdio.h>

typedef char string[100];

typedef struct {
  string name;
  string lastname;
  int age;
  double height;
} person;

int main(void) {
  person a_person;
  printf("Input data for a person\n");
  printf("First name: ");
  scanf("%99s", a_person.name);
  printf("Last name: ");
  scanf("%99s", a_person.lastname);
  printf("Age: ");
  scanf("%d", &a_person.age);
  printf("Height: ");
  scanf("%lf", &a_person.height);
  printf("Person's data\n");
  printf("%s %s\n", a_person.name, a_person.lastname);
  printf("%d %lf\n", a_person.age, a_person.height);
  if (a_person.age >= 18) {
    printf("Adult\n");
  } else {
    printf("Not an adult\n");
  }
  return 0;
}
