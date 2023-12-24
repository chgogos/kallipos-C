#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(void) {
  struct timeval current_time;
  gettimeofday(&current_time, NULL);
  long seed = current_time.tv_usec;
  srand(seed);
  printf("SEED = %ld\n", seed);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      double r = (double)rand() / (double)RAND_MAX;
      printf("%.4lf ", r);
    }
    printf("\n");
  }
  return 0;
}
