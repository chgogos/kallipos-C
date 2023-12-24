#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_elements(char *line, int *code, double *lec, double *lab) {
  int icount = 0;
  char *token;
  token = strtok(line, ",");
  while (token != NULL) {
    icount++;
    if (icount == 1) {
      *code = atoi(token);
    } else if (icount == 2) {
      *lec = atof(token);
    } else {
      *lab = atof(token);
    }
    token = strtok(NULL, ",");
  }
}

int main(void) {
  int code, maxcode, count = 0;
  double lab, lecture, average, maxaverage;
  char line[256];
  FILE *fp = fopen("grades.csv", "r");
  if (fp == NULL) {
    printf("File could not be opened\n");
    return EXIT_FAILURE;
  }
  while (fgets(line, 256, fp)) {
    get_elements(line, &code, &lecture, &lab);
    average = (lecture + lab) / 2.;
    if (count == 0 || average > maxaverage) {
      maxcode = code;
      maxaverage = average;
    }
    count++;
  }
  fclose(fp);
  printf("Number of students: %d\n", count);
  printf("The student with the best performance is: %d\n", maxcode);
  printf("The best average grade is               : %lf\n", maxaverage);
  return 0;
}
