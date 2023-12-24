#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void) {
  int code, maxcode;
  double lab, lecture, average, maxaverage;
  FILE *fp = fopen("grades.txt", "r");
  if (fp == NULL) {
    printf("File could not be opened\n");
    return EXIT_FAILURE;
  }
  for (int i = 0; i < SIZE; i++) {
    fscanf(fp, "%d %lf %lf", &code, &lecture, &lab);
    average = (lecture + lab) / 2.;
    if (i == 0 || average > maxaverage) {
      maxcode = code;
      maxaverage = average;
    }
  }
  fclose(fp);
  printf("The student with the best performance is: %d\n", maxcode);
  printf("The best average grade is               : %lf\n", maxaverage);
  return 0;
}
