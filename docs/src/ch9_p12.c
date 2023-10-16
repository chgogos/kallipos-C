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
  printf("Student details: %s %s %d %.2lf \n", t->name, t->lastname, t->id,
         get_average(t));
}

int main(void) {
  student *s1 = malloc(sizeof(student));
  strcpy(s1->name, "Giannis");
  strcpy(s1->lastname, "Ioannou");
  s1->id = 100;
  s1->lessons = 3;
  s1->grades = malloc(s1->lessons * sizeof(double));
  s1->grades[0] = 5;
  s1->grades[1] = 7;
  s1->grades[2] = 8;
  print_student(s1);
  free(s1->grades);
  free(s1);
  return 0;
}
