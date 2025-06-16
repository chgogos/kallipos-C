#include <stdio.h>
#include <string.h>

#define NLESSONS 3

struct student {
  int id;
  char name[100], lastname[100];
  double lessons[NLESSONS];
};

double average(const double x[], int n) {
  int i;
  double sum = 0.0;
  for (i = 0; i < n; i++)
    sum += x[i];
  return sum / n;
}

int main(void) {
  struct student giannis;
  strcpy(giannis.name, "Giannis");
  strcpy(giannis.lastname, "Pappas");
  giannis.id = 1000;
  giannis.lessons[0] = 8.5;
  giannis.lessons[1] = 7.;
  giannis.lessons[2] = 6.5;
  printf("Average grade for [%d, %s, %s]: %.2lf\n", giannis.id,
         giannis.lastname, giannis.name, average(giannis.lessons, NLESSONS));
  return 0;
}
