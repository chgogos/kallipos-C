#include <stdio.h>
#include <math.h>

#define NLESSONS 3

typedef struct {
  int id;
  char name[100], lastname[100];
  double lessons[NLESSONS];
} student;

double average(const double x[], int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += x[i];
  }
  return sum / n;
}

int is_better(student first, student second) {
  // στρογγυλοποίηση στο δεύτερο δεκαδικό ψηφίο με τη roundf
  float avg_first = roundf(average(first.lessons, NLESSONS) * 100.0) / 100.0;
  float avg_second = roundf(average(second.lessons, NLESSONS) * 100.0) / 100.0;

  if (avg_first > avg_second) {
    return 1;
  } else if (avg_first == avg_second) {
    return 0;
  } else {
    return -1;
  }
}

int main(void) {
  student giannis = {1000, "Giannis", "Pappas", {8.5, 9., 7.5}};
  student nikos = {1001, "Nikos", "Ioannou", {6.5, 9., 5.}};
  if (is_better(giannis, nikos) == 1) {
    printf(
        "Student %s %s (%d) has better average grade than student %s %s (%d)\n",
        giannis.name, giannis.lastname, giannis.id, nikos.name, nikos.lastname,
        nikos.id);
  } else if (is_better(giannis, nikos) == -1) {
    printf(
        "Student %s %s (%d) has better average grade than student %s %s (%d)\n",
        nikos.name, nikos.lastname, nikos.id, giannis.name, giannis.lastname,
        giannis.id);
  } else {
    printf("Both students have the same average grade\n");
  }
  return 0;
}
