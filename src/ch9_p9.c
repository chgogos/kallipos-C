#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // αρχικοποίηση της συνάρτησης rand()
  double *d = calloc(
      10, sizeof(double)); // δέσμευση μνήμης για 10 double με αρχική τιμή 0
  for (int i = 0; i < 5; i++) {
    d[i] = rand() * 1.0 / RAND_MAX; // τυχαίος αριθμός από το 0 έως το 1
  }
  for (int i = 0; i < 10; i++) {
    printf("%.4lf ", d[i]);
  }
  free(d);
  return 0;
}
