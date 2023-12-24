#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[100];
  char lastname[100];
  int id;
  int semester;
} student;

int main(void) {
  FILE *fp = fopen("students.txt", "w");
  if (fp == NULL) {
    printf("Write failed!\n");
    return EXIT_FAILURE;
  }
  student student1 = {"John", "Doe", 100, 5};
  fprintf(fp, "%s %s %d %d\n", student1.name, student1.lastname, student1.id,
          student1.semester);
  student student2 = {"Jane", "Doe", 101, 5};
  fprintf(fp, "%s %s %d %d\n", student2.name, student2.lastname, student2.id,
          student2.semester);
  fclose(fp);
  return 0;
}
