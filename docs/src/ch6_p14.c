#include <stdio.h>

typedef struct {
  char lastname[100];
  int depid;
  double salary;
} employee;

employee read_employee(void) {
  employee p;
  printf("Input name, department id and month salary of employee: ");
  scanf("%99s %d %lf", p.lastname, &p.depid, &p.salary);
  return p;
}

int main(void) {
  employee table[5];
  int total = 0;
  for (int i = 0; i < 5; i++) {
    table[i] = read_employee();
    if (table[i].salary < 1000)
      total++;
  }
  printf("%d employees are payed less than 1000 euro per month\n", total);
  return 0;
}
