#include <gsl/gsl_linalg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int n;
  printf("Enter the size of the vectors: ");
  scanf("%d", &n);
  srand(time(NULL));
  double *x = (double *)malloc(n * sizeof(double));
  double *y = (double *)malloc(n * sizeof(double));
  for (int i = 0; i < n; i++) {
    x[i] = (double)rand() / (double)(RAND_MAX / 100);
    y[i] = (double)rand() / (double)(RAND_MAX / 100);
  }
  double result;
  gsl_vector_view X = gsl_vector_view_array(x, 3);
  gsl_vector_view Y = gsl_vector_view_array(y, 3);
  gsl_blas_ddot(&X.vector, &Y.vector, &result);
  printf("The dot product is %g\n", result);
  return 0;
}
