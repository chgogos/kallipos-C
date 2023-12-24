#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rows, cols;
  double **table;
  printf("Input number of rows: ");
  scanf("%d", &rows);
  printf("Input number of columns: ");
  scanf("%d", &cols);
  table = malloc(sizeof(double *) * rows);
  for (int i = 0; i < rows; i++) {
    table[i] = malloc(sizeof(double) * cols);
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      table[i][j] = i  + j ;
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.1lf\t", table[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < rows; i++) {
    free(table[i]);
  }
  free(table);
  return 0;
}
