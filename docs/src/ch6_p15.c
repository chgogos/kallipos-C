#include <stdio.h>

typedef struct {
  char lastname[100];
  int depid;
  double salary;
} employee;

void sort_employee(employee t[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1; j++) {
      if (t[j + 1].salary > t[j].salary) {
        employee temp;
        temp = t[j];
        t[j] = t[j + 1];
        t[j + 1] = temp;
      }
    }
  }
}

int main(void) {
  employee table[5] = {{"Ioannou", 100, 1900.0},
                       {"Pappas", 200, 800.50},
                       {"Dimitriou", 100, 1320.55},
                       {"Christou", 200, 761.53},
                       {"Evangelou", 100, 1190.55}};
  sort_employee(table, 5);
  for (int i = 0; i < 5; i++) {
    printf("Employee: %2d Lastname: %10s Department: %4d Salary: %10.2lf\n",
           i + 1, table[i].lastname, table[i].depid, table[i].salary);
  }
  return 0;
}
