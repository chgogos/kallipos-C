#include <stdio.h>

#define NLESSONS 3

typedef struct {
  int id;
  char name[100], lastname[100];
  double lessons[NLESSONS];
} student;

double average(double x[], int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += x[i];
  }
  return sum / n;
}

int is_better(student first, student second) {
  return average(first.lessons, NLESSONS) > average(second.lessons, NLESSONS)
             ? 1
             : 0;
}

int main(void) {
  student giannis = {1000, "Giannis", "Pappas", 8.5, 9., 7.5};
  student nikos = {1001, "Nikos", "Ioannou", 6.5, 9., 5.};
  if (is_better(giannis, nikos)) {
    printf("Student %s has better average grade than student %s\n",
           giannis.name, nikos.name);
  } else {
    printf("Student %s has better average grade than student %s\n", nikos.name,
           giannis.name);
  }
  return 0;
}