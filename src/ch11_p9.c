#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int code, maxcode;
  double lab, lecture, average, maxaverage;
  int count = 0;
  FILE *fp = fopen("grades.txt", "r");
  if (fp == NULL) {
    printf("File could not be opened\n");
    return EXIT_FAILURE;
  }
  while (fscanf(fp, "%d %lf %lf", &code, &lecture, &lab) > 0) {
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
