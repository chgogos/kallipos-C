#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[100], lastname[100];
  int id;
  int lessons;
  double *grades;
} student;

double get_average(student *t) {
  double s = 0.0;
  for (int i = 0; i < t->lessons; i++) {
    s = s + t->grades[i];
  }
  return s / t->lessons;
}

void print_student(student *t) {
  printf("Id:%d name:%s %s average grade:%.2lf \n", t->id, t->name, t->lastname,
         get_average(t));
}

int main(void) {
  student *s1 = malloc(sizeof(student));
  strcpy(s1->name, "Jane");
  strcpy(s1->lastname, "Doe");
  s1->id = 100;
  s1->lessons = 3;
  s1->grades = malloc(s1->lessons * sizeof(double));
  s1->grades[0] = 5.5;
  s1->grades[1] = 7.;
  s1->grades[2] = 8.;
  print_student(s1);
  free(s1->grades);
  free(s1);
  return 0;
}
