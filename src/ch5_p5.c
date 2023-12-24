#include <stdio.h>

void calculate_totals(int arr[][4], int row_totals[], int col_totals[]) {
  int i, j;
  // Αθροίσματα ανά γραμμές
  for (i = 0; i < 3; i++) {
    row_totals[i] = 0;
    for (j = 0; j < 4; j++) {
      row_totals[i] += arr[i][j];
    }
  }
  // Αθροίσματα ανά στήλες
  for (j = 0; j < 4; j++) {
    col_totals[j] = 0;
    for (i = 0; i < 3; i++) {
      col_totals[j] += arr[i][j];
    }
  }
}

int main(void) {
  int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int row_totals[3], col_totals[4];
  calculate_totals(array, row_totals, col_totals);
  printf("Row Totals: ");
  for (int i = 0; i < 3; i++) {
    printf("%d ", row_totals[i]);
  }
  printf("\nColumn Totals: ");
  for (int j = 0; j < 4; j++) {
    printf("%d ", col_totals[j]);
  }
  return 0;
}
