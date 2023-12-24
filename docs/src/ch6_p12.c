#include <stdio.h>

typedef struct {
  int year;
  int month;
  int day;
} date;

typedef struct {
  char name[100];
  char lastname[100];
  date birthdate;
} person;

date read_date(void) {
  date d;
  printf("Input a birth date: ");
  scanf("%d%d%d", &d.day, &d.month, &d.year);
  return d;
}

void print_date(date d) { printf("%d/%d/%d\n", d.day, d.month, d.year); }

person read_person(void) {
  person p;
  printf("Input first name and last name: ");
  scanf("%99s%99s", p.name, p.lastname);
  p.birthdate = read_date();
  return p;
}

void print_person(person p) {
  printf("Person's data:\n");
  printf("%s, %s\n", p.name, p.lastname);
  print_date(p.birthdate);
}

int main(void) {
  person a_person;
  a_person = read_person();
  print_person(a_person);
  return 0;
}
