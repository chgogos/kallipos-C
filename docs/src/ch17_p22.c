#include <gsl/gsl_permutation.h>
#include <stdio.h>

void print_permutation(const gsl_permutation *p, char *names[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%s ", names[gsl_permutation_get(p, i)]);
  }
  printf("\n");
}

int main(void) {
  char *names[] = {"Alice", "Bob", "Charlie"};
  size_t size = sizeof(names) / sizeof(names[0]);

  gsl_permutation *p = gsl_permutation_alloc(size);
  gsl_permutation_init(p);

  do {
    print_permutation(p, names, size);
  } while (gsl_permutation_next(p) == GSL_SUCCESS);

  gsl_permutation_free(p);
  return 0;
}
