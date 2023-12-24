#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, i, j, sum = 0;
  printf("Enter the dimension of the square matrix: ");
  scanf("%d", &n);
  int **array = calloc(n, sizeof(int *));
  for (i = 0; i < n; i++) {
    array[i] = calloc(n, sizeof(int));
  }
  printf("Enter the elements of the matrix diagonal:\n");
  for (i = 0; i < n; i++) {
    printf("Element [%d,%d]: ", i + 1, i + 1);
    scanf("%d", &(array[i][i]));
    sum += array[i][i];
  }
  printf("The matrix is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("The sum of the diagonal elements is: %d\n", sum);
  for (i = 0; i < n; i++) {
    free(array[i]);
  }
  free(array);
  return 0;
}
