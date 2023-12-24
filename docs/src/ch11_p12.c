#include <stdio.h>
#include <stdlib.h>

// αναδρομική συνάρτηση υπολογισμού του n-οστού όρου
// της ακολουθίας fibonacci (προσοχή στην απόδοση της συνάρτησης).
int fib(int n) {
  if (n <= 1)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
  FILE *fp = fopen("fibonacci20.txt", "w");
  if (fp == NULL) {
    printf("Write failed!\n");
    return EXIT_FAILURE;
  }
  for (int i = 0; i < 10; i++) {
    fprintf(fp, "%4d %4d\n", i + 1, fib(i));
  }
  fclose(fp);
  return 0;
}
