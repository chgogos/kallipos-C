#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[100];
  char lastname[100];
} person;

int main(void) {
  person a_person;
  person *pt = &a_person;
  printf("The pointer %p points to a 'person'\n", (void*)pt);
  printf("Each 'person' occupies %ld bytes\n", sizeof(person));
  strcpy((*pt).name, "Ioannis"); // α' τρόπος πρόσβασης σε πεδίο δομής
  strcpy(pt->lastname, "Pappas"); // β' τρόπος πρόσβασης σε πεδίο δομής
  pt->id = 1000; // β' τρόπος πρόσβασης σε πεδίο δομής
  printf("Id: %d, name: %s, last name: %s\n", a_person.id, a_person.name,
         a_person.lastname);
  return 0;
}
